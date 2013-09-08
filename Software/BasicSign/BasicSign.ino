/* Example scrolling signboard app for GrrCON 2013 badges */
/* Author: Mark Farver                                    */
/* Date:   26 Aug 2013                                    */
/*
The MIT License (MIT)

Copyright (c) 2013 Mark Farver

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "EEPROM.h"
#include "font5x7.h"

#define shift_latch_bit_pos    7
#define shift_clock_bit_pos    6
#define shift_data_bit_pos     5

#define shift_latch_mask       1 << shift_latch_bit_pos
#define shift_clock_mask       1 << shift_clock_bit_pos
#define shift_data_mask        1 << shift_data_bit_pos

#define MSG_LENGTH_ADDR 0
#define START_OF_MSG_ADDR MSG_LENGTH_ADDR + 1
#define MAX_MSG_LENGTH 254

boolean reload;
int message_num_cols;
char message[MAX_MSG_LENGTH];

// keeps track of which demo function is being run currently
unsigned char current_demo;

//number columns offset into the message, where screen draw should start
unsigned int current_col;

//How many times should we paint the matrix before scrolling it
const int SCROLL_REFRESH = 20;

//keeps track of number of refreshes, counts up to SCROLL_REFRESH
int scroll_count;

unsigned int write_buffer_index = 0;
unsigned int eol_counter = 0;
char writebuffer[MAX_MSG_LENGTH];

void load_msg() {
  //We need to load the message length
  //The message is stored in a Pascal string in EEPROM
  message_num_cols = EEPROM.read(MSG_LENGTH_ADDR);
  
  // if the EEPROM has not been initialized, we have no message
  if(message_num_cols == 0xFF) {
    message_num_cols = 0;
  }

  // copy the message from EEPROM (which is slow)
  for(unsigned int i = 0; i < message_num_cols; ++i) {
    message[i] = EEPROM.read(START_OF_MSG_ADDR + i);
  }

  message_num_cols *= CHAR_WIDTH;
  current_col = 0;
  scroll_count = 0;
  current_demo = 0;
  reload = false;
}

void clear_writebuf() {
  write_buffer_index = 0;
  eol_counter = 0;
}

void setup() {                
  pinMode(shift_latch_bit_pos, OUTPUT);     
  pinMode(shift_clock_bit_pos, OUTPUT);     
  pinMode(shift_data_bit_pos, OUTPUT);  
  Serial.begin(9600);
  
  load_msg();
  clear_writebuf();
}

// forward-declare demo routine
void demo();

// the loop routine runs over and over again forever:
void loop() {
  // reload message, if signalled to do so
  if(reload) {
    load_msg();
  }
  
  // no message defined: demo routine
  if(message_num_cols == 0) {
    demo();
    return;
  }

  for (int i=0; i < 8; ++i) {
    unsigned int print_col = (current_col + i) % message_num_cols;
    char letter = message[print_col / CHAR_WIDTH];
    if((letter < FIRST_CHAR) || (letter > LAST_CHAR)) {
      letter = FIRST_CHAR;
    }
    unsigned int offset = print_col % CHAR_WIDTH;
    writeCol(i, font5x7[ (letter - FIRST_CHAR) * CHAR_WIDTH + offset]);
  }  

  if ( ++scroll_count > SCROLL_REFRESH ) {
     scroll_count = 0;
     current_col = (current_col + 1) % message_num_cols;
  }
}

// Not compatible with Esplora, Leonardo, or Micro
void serialEvent() 
{
  if (Serial.available() > 0) 
  {
    unsigned char newchar = Serial.read();
    Serial.write(newchar);
    if (newchar == '\n' || newchar == '\0')
    {
      if ( ++eol_counter >= 3) {
        for (int i = 0; i < write_buffer_index; ++i) {
          EEPROM.write(START_OF_MSG_ADDR + i, writebuffer[i]); 
        }
        EEPROM.write(MSG_LENGTH_ADDR, write_buffer_index);

		clear_writebuf();
        // signal a message load on next loop
		reload = true;
      }
    }
    else if (newchar == '\r') // Windows only, immediately followed by an \n
    {
      // pass
    }
    else if (newchar == 0x01) // ctrl-a
    {
      Serial.println(EEPROM.read(MSG_LENGTH_ADDR), DEC);
    }
	else if (newchar == 0x03) // ctrl-c
	{
	  // abort the current string
	  clear_writebuf();
	}
    else
    {
      write_buffer_index = (write_buffer_index++) % MAX_MSG_LENGTH;
      writebuffer[write_buffer_index] = newchar;
      eol_counter = 0;
    }
  }
}

void writeCol(unsigned int col, unsigned int data){
  //The selected column must be driven low, and the
  //lowest number column is actually the rightmost
  //to simplify things we reorder it by shifting left
  //so column 0 is on the left.
  write_shift_reg( ~(0x80 >> col) );
  write_shift_reg( data );
  strobe_latch();
}

void strobe_latch() {
  PORTD |= shift_latch_mask;
  PORTD &= ~shift_latch_mask;
}

void write_shift_reg(unsigned int write_me) {
  int i;
  int mask = 0x80;
  for (i=0; i<8; ++i) {
    PORTD &= ~shift_clock_mask;  //Set Clock Low
    if ( write_me & mask ) 
      PORTD |= shift_data_mask;
    else   
      PORTD &= ~shift_data_mask;
    PORTD |= shift_clock_mask;  //Set Clock H
    mask >>= 1;
  }
}

void demo() {
  const unsigned char DEMO_COUNT = 2;

  if(current_demo == 0) {
    // all LEDs on
	for(char i = 0; i < 8; ++i) {
	  writeCol(i, 0x7F);
	}
	if(++scroll_count > SCROLL_REFRESH) {
	  scroll_count = 0;
	  ++current_demo;
	  current_col = 0;
	}
  } else if(current_demo == 1) {
    // one LED on, dropping down each column from left to right
	unsigned int col = current_col / 7;
	unsigned int row_mask = 1 << (current_col % 7);
	for(char i = 0; i < 8; ++i) {
	  if(i != col) {
	    writeCol(i, 0);
	  } else {
	    writeCol(i, row_mask);
	  }
	}
	if(++scroll_count > SCROLL_REFRESH) {
	  scroll_count = 0;
	  ++current_col;
	}
	if(current_col > 56) {
	  current_col = 0;
	  ++current_demo;
	}
  }

  // and loop around
  current_demo %= DEMO_COUNT;
}
