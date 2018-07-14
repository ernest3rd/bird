#include "hero.h"

Hero::Hero(){
    setup(0,0);
}

void Hero::setup(int x, int y){
    start_x = x;
    start_y = y;
    reset();
}

void Hero::reset(){
    x = start_x;
    y = start_y;
    vy = 0;
}

void Hero::update(float delta, bool button){
  y += vy * delta;
    if(y > 7){
        y = 7;
        vy = 0;
    }
    else if(y<0){
        y = 0;
        vy = 0;
    }

  if(!button_down){
    if(button){
        //flap = 2;
      button_down = true;
        //vy-=LIFT_AMOUNT;
    }
  }
  else {
    if(!button){
      button_down = false;
    }
  }
    
    if(button_down){
        flap = 1;
        vy-=GRAVITY*2*delta;
    }
    else{
        flap = 0;
        vy+=GRAVITY*delta;
    }
    
   /* if(flap > 0){
        flap -= delta;
    }*/
}

void Hero::draw(VideoBuffer *vb){
    draw(vb, false);
}

void Hero::draw(VideoBuffer *vb, bool invert){
    vb->setPixel((int)x,   (int)y, !invert);
    vb->setPixel((int)x+1,   (int)y, !invert);
    if(flap > 0 && millis() % 200 < 100){
        vb->setPixel((int)x, (int)y+1, true);
    }
}

bool Hero::testCollision(Wall *wall){
  //for(int i=0; i<2; i++){
    //for(int j=1; j<2; j++){
      if(wall->testPixel(int(x+1), int(y))){
        // Collision with wall
        return true;
      }  
    //}
  //}

  return false;
}

