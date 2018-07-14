#ifndef Wall_h
#define Wall_h

#include "Arduino.h"
#include "videoBuffer.h"

class Wall {
  public:
    Wall();
    void setup(int width, int height);
    void update(float delta);
    void draw(VideoBuffer *vb);
    void draw(VideoBuffer *vb, bool invert);
    bool testPixel(int x, int y);
    void reset();
    int getLevel();
  private:
    void nextLevel();
  
    float x, speed;
    int width, height, level, thickness;
    bool *pixels;
};

#endif

