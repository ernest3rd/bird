#ifndef VideoBuffer_h
#define VideoBuffer_h

#include "Arduino.h"

class VideoBuffer
{
  public:
    VideoBuffer(int width, int height, int first_pin, int reset_pin, int clock_pin);
    void setup(int width, int height, int first_pin, int reset_pin, int clock_pin);
    void flush();
    void setPixel(int x, int y, bool on);
    void setPixel(int i, bool on);
    bool getPixel(int x, int y);
    bool getPixel(int i);
    void clear();
  private:
    void lightRow();
    void dimRow();
    void advance();
    void reset();
    
    int width = 0, height = 0;
    int reset_pin = 0, clock_pin = 0;
    int refresh_rate = int(1000000/60.0/10);
    unsigned long last_millis = 0;
    int current_row = 0;
    int *row_pins; //[8] = {6,7,8,9,10,11,12,13};
    bool *vbuffer;/*[80] = {
      0,0,0,0,0,0,0,0, // 0
      0,0,0,0,0,0,0,0, // 1
      0,0,0,0,0,0,0,0, // 2
      0,0,0,0,0,0,0,0, // 3
      0,0,0,0,0,0,0,0, // 4
      0,0,0,0,0,0,0,0, // 5
      0,0,0,0,0,0,0,0, // 6
      0,0,0,0,0,0,0,0, // 7
      0,0,0,0,0,0,0,0, // 8
      0,0,0,0,0,0,0,0  // 9
    };*/
};

#endif

