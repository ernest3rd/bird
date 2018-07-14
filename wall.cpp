#include "wall.h"

Wall::Wall(){
    setup(0,0);
}

void Wall::setup(int width, int height){
  this->width = width;
  this->height = height;
  
  reset();
  
  if(!pixels){
    free(pixels);
  }
    pixels = (bool *)calloc(sizeof(bool), width);
}

void Wall::reset(){
  speed = 0.3;
  level = 0;
  nextLevel();
}

void Wall::update(float delta){
  x -= speed * delta;
  if(x+thickness < 0){
    nextLevel();
  }
}

void Wall::draw(VideoBuffer *vb){
    draw(vb, false);
}

void Wall::draw(VideoBuffer *vb, bool invert){
    for(int y=0; y<height; y++){
        for(int dx=0; dx<thickness; dx++){
            if(pixels[y]){
                vb->setPixel(x+dx, y, !invert);
            }
        }
    }
}

bool Wall::testPixel(int x, int y){
    return (x >= (int)this->x && x < (int)this->x+thickness-1) && pixels[y];
}

void Wall::nextLevel(){
  level++;
    thickness = int(random(4)+2);
  int obstacle = level/6 + 4;
    if(obstacle > height -2)
        obstacle = height-2;
  int split = (int)random(obstacle);
  for(int i=0; i<height; i++){
      if(i<split || i>height-1-obstacle+split){
        pixels[i] = 1;
      }
      else {
        pixels[i] = 0;
      }
  }
  x = width + 1;
}

int Wall::getLevel(){
    return level;
}

