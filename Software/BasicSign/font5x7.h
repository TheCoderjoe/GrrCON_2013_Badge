/* 5x7 Fixed width font developed for GrrCON 2013 badges */
/* Author: Mark Farver                                   */
/* Date:   26 Aug 2013                                   */
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

const int CHAR_WIDTH = 6;
const char FIRST_CHAR = ' ';
const char font5x7[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 
0x04, 0x03, 0x00, 0x04, 0x03, 0x00, 
0x14, 0x3E, 0x14, 0x3E, 0x14, 0x00, 
0x24, 0x2A, 0x6B, 0x2A, 0x12, 0x00, 
0x22, 0x10, 0x08, 0x04, 0x22, 0x00, 
0x36, 0x49, 0x55, 0x22, 0x50, 0x00, 
0x00, 0x00, 0x04, 0x03, 0x00, 0x00, 
0x00, 0x00, 0x1C, 0x22, 0x41, 0x00, 
0x00, 0x41, 0x22, 0x1C, 0x00, 0x00, 
0x14, 0x08, 0x3E, 0x08, 0x14, 0x00, 
0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 
0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 
0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 
0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 
0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 
0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, 
0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, 
0x62, 0x51, 0x49, 0x45, 0x42, 0x00, 
0x00, 0x41, 0x49, 0x49, 0x36, 0x00, 
0x07, 0x08, 0x08, 0x08, 0x7F, 0x00, 
0x47, 0x49, 0x49, 0x49, 0x31, 0x00, 
0x3E, 0x49, 0x49, 0x49, 0x32, 0x00,
0x61, 0x11, 0x09, 0x05, 0x03, 0x00, 
0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 
0x06, 0x49, 0x49, 0x49, 0x3E, 0x00, 
0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 
0x00, 0x56, 0x36, 0x00, 0x00, 0x00, 
0x00, 0x08, 0x14, 0x22, 0x41, 0x00, 
0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 
0x00, 0x41, 0x22, 0x14, 0x08, 0x00, 
0x02, 0x01, 0x59, 0x05, 0x02, 0x00, 
0x32, 0x49, 0x79, 0x41, 0x3E, 0x00, 
0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00,
0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, 
0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 
0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00, 
0x7F, 0x49, 0x49, 0x49, 0x49, 0x00, 
0x7F, 0x09, 0x09, 0x09, 0x09, 0x00, 
0x3E, 0x41, 0x41, 0x49, 0x39, 0x00, 
0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 
0x41, 0x41, 0x7F, 0x41, 0x41, 0x00, 
0x20, 0x40, 0x40, 0x40, 0x3F, 0x00, 
0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 
0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, 
0x7F, 0x06, 0x0C, 0x06, 0x7F, 0x00, 
0x7F, 0x02, 0x0C, 0x10, 0x7F, 0x00, 
0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 
0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, 
0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, 
0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, 
0x46, 0x49, 0x49, 0x49, 0x31, 0x00, 
0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, 
0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00, 
0x07, 0x18, 0x60, 0x18, 0x07, 0x00, 
0x7F, 0x30, 0x18, 0x30, 0x7F, 0x00, 
0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 
0x07, 0x08, 0x78, 0x08, 0x07, 0x00, 
0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, 
0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 
0x41, 0x41, 0x7F, 0x00, 0x00, 0x00,
0x04, 0x02, 0x01, 0x02, 0x04, 0x00, 
0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 
0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 
0x20, 0x54, 0x54, 0x54, 0x78, 0x00, 
0x3F, 0x48, 0x48, 0x48, 0x30, 0x00, 
0x30, 0x48, 0x48, 0x48, 0x48, 0x00, 
0x30, 0x48, 0x48, 0x48, 0x3F, 0x00, 
0x38, 0x54, 0x54, 0x54, 0x08, 0x00, 
0x08, 0x7E, 0x09, 0x09, 0x02, 0x00, 
0x48, 0x54, 0x54, 0x54, 0x38, 0x00, 
0x7F, 0x08, 0x08, 0x08, 0x70, 0x00, 
0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 
0x20, 0x40, 0x40, 0x3A, 0x00, 0x00, 
0x7F, 0x10, 0x28, 0x44, 0x00, 0x00, 
0x00, 0x41, 0x7F, 0x40, 0x00, 0x00, 
0x78, 0x04, 0x18, 0x04, 0x78, 0x00, 
0x78, 0x04, 0x04, 0x04, 0x78, 0x00, 
0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 
0x78, 0x14, 0x14, 0x14, 0x08, 0x00, 
0x08, 0x14, 0x14, 0x14, 0x78, 0x00, 
0x7C, 0x08, 0x04, 0x04, 0x08, 0x00, 
0x48, 0x54, 0x54, 0x54, 0x24, 0x00, 
0x08, 0x3E, 0x48, 0x28, 0x00, 0x00, 
0x3C, 0x40, 0x40, 0x40, 0x3C, 0x00, 
0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00, 
0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00, 
0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 
0x44, 0x28, 0x10, 0x08, 0x04, 0x00, 
0x44, 0x64, 0x54, 0x4C, 0x44, 0x00, 
0x00, 0x08, 0x36, 0x41, 0x41, 0x00, 
0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 
0x41, 0x41, 0x36, 0x08, 0x00, 0x00, 
0x02, 0x01, 0x01, 0x02, 0x01, 0x00,
0x56, 0x2D, 0x2F, 0x2D, 0x56, 0x00
};

const char LAST_CHAR = FIRST_CHAR + (sizeof(font5x7) / CHAR_WIDTH) - 1;

