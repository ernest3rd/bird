//
//  charDrawer.h
//  mySketch
//
//  Created by Juhani Halkomäki on 05/03/2018.
//

#ifndef charDrawer_h
#define charDrawer_h

#include <stdio.h>
#include <string.h>
#include "videoBuffer.h"

const int LETTER_WIDTH = 3;
const int LETTER_HEIGHT = 5;
const unsigned int LETTER_0 = 0x7b6f;
const unsigned int LETTER_1 = 0x749a;
const unsigned int LETTER_2 = 0x772a;
const unsigned int LETTER_3 = 0x38a3;
const unsigned int LETTER_4 = 0x49ed;
const unsigned int LETTER_5 = 0x39cf;
const unsigned int LETTER_6 = 0x7ace;
const unsigned int LETTER_7 = 0x12a7;
const unsigned int LETTER_8 = 0x7bef;
const unsigned int LETTER_9 = 0x39af;

const unsigned int LETTER_A = 0x5bea;
const unsigned int LETTER_B = 0x3aeb;
const unsigned int LETTER_C = 0x2a6a;
const unsigned int LETTER_D = 0x3b6b;
const unsigned int LETTER_E = 0x72cf;
const unsigned int LETTER_F = 0x12cf;
const unsigned int LETTER_G = 0x2b4e;
const unsigned int LETTER_H = 0x5bed;
const unsigned int LETTER_I = 0x7497;
const unsigned int LETTER_J = 0x7b24;
const unsigned int LETTER_K = 0x5aed;
const unsigned int LETTER_L = 0x7249;
const unsigned int LETTER_M = 0x5b7d;
const unsigned int LETTER_N = 0x5ffd;
const unsigned int LETTER_O = 0x2b6a;
const unsigned int LETTER_P = 0x12eb;
const unsigned int LETTER_Q = 0x456a;
const unsigned int LETTER_R = 0x5aeb;
const unsigned int LETTER_S = 0x388e;
const unsigned int LETTER_T = 0x2497;
const unsigned int LETTER_U = 0x7b6d;
const unsigned int LETTER_V = 0x2b6d;
const unsigned int LETTER_W = 0x5f6d;
const unsigned int LETTER_X = 0x5aad;
const unsigned int LETTER_Y = 0x24ad;
const unsigned int LETTER_Z = 0x72a7;

const unsigned int LETTER_SPACE = 0x0000;

void drawChar(char chr, int x, int y, VideoBuffer *vb);
void drawString(const char *str, int x, int y, VideoBuffer *vb);
unsigned int stringLengthInPixels(const char *str);
unsigned int getChar(char chr);
int *get_bits(int n, int bitswanted);

#endif /* charDrawer_h */

