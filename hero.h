#ifndef Hero_h
#define Hero_h

#define LIFT_AMOUNT 0.4
#define GRAVITY 0.05

#include "Arduino.h"
#include "videoBuffer.h"
#include "wall.h"

class Hero {
  public:
    Hero();
    void setup(int x, int y);
    void update(float delta, bool button);
    void draw(VideoBuffer *vb);
    void draw(VideoBuffer *vb, bool invert);
    bool testCollision(Wall *wall);
    void reset();
  private:
    float start_x, start_y;
    float x, y;
    float vy;
    float flap = 0;
    bool button_down = false;
};

#endif

