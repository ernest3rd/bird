//
//  charDrawer.cpp
//  mySketch
//
//  Created by Juhani Halkomäki on 05/03/2018.
//

#include "charDrawer.h"

void drawChar(char chr, int x, int y, VideoBuffer *vb){
    int *bits = get_bits(getChar(chr), 15);
    for(int dx=0; dx<LETTER_WIDTH; dx++){
        for(int dy=0; dy<LETTER_HEIGHT; dy++){
            if(bits[dx+dy*LETTER_WIDTH] == 1)
                vb->setPixel((x+dx),(y+dy), true);
        }
    }
    free(bits);
}
void drawString(const char *str, int x, int y, VideoBuffer *vb){
    for(int i=0; i<strlen(str); i++){
        drawChar(str[i], x+i*(LETTER_WIDTH+1), y, vb);
    }
}

unsigned int stringLengthInPixels(const char *str){
    return strlen(str) * (LETTER_WIDTH+1);
}

unsigned int getChar(char chr){
    switch(chr) {
        case '0':
            return LETTER_0;
            break;
        case '1':
            return LETTER_1;
            break;
        case '2':
            return LETTER_2;
            break;
        case '3':
            return LETTER_3;
            break;
        case '4':
            return LETTER_4;
            break;
        case '5':
            return LETTER_5;
            break;
        case '6':
            return LETTER_6;
            break;
        case '7':
            return LETTER_7;
            break;
        case '8':
            return LETTER_8;
            break;
        case '9':
            return LETTER_9;
            break;
        default:
            return LETTER_0;
            break;
        case 'a':
        case 'A':
            return LETTER_A;
            break;
        case 'b':
        case 'B':
            return LETTER_B;
            break;
        case 'c':
        case 'C':
            return LETTER_C;
            break;
        case 'd':
        case 'D':
            return LETTER_D;
            break;
        case 'e':
        case 'E':
            return LETTER_E;
            break;
        case 'f':
        case 'F':
            return LETTER_F;
            break;
        case 'g':
        case 'G':
            return LETTER_G;
            break;
        case 'h':
        case 'H':
            return LETTER_H;
            break;
        case 'i':
        case 'I':
            return LETTER_I;
            break;
        case 'j':
        case 'J':
            return LETTER_J;
            break;
        case 'k':
        case 'K':
            return LETTER_K;
            break;
        case 'l':
        case 'L':
            return LETTER_L;
            break;
        case 'm':
        case 'M':
            return LETTER_M;
            break;
        case 'n':
        case 'N':
            return LETTER_N;
            break;
        case 'o':
        case 'O':
            return LETTER_O;
            break;
        case 'p':
        case 'P':
            return LETTER_P;
            break;
        case 'q':
        case 'Q':
            return LETTER_Q;
            break;
        case 'r':
        case 'R':
            return LETTER_R;
            break;
        case 's':
        case 'S':
            return LETTER_S;
            break;
        case 't':
        case 'T':
            return LETTER_T;
            break;
        case 'u':
        case 'U':
            return LETTER_U;
            break;
        case 'v':
        case 'V':
            return LETTER_V;
            break;
        case 'w':
        case 'W':
            return LETTER_W;
            break;
        case 'x':
        case 'X':
            return LETTER_X;
            break;
        case 'y':
        case 'Y':
            return LETTER_Y;
            break;
        case 'z':
        case 'Z':
            return LETTER_Z;
            break;
        case ' ':
            return LETTER_SPACE;
            break;
            
    }
}

int *get_bits(int n, int bitswanted){
    int *bits = (int *)malloc(sizeof(int) * bitswanted);
    
    int k;
    for(k=0; k<bitswanted; k++){
        int mask =  1 << k;
        int masked_n = n & mask;
        int thebit = masked_n >> k;
        bits[k] = thebit;
    }
    
    return bits;
}

