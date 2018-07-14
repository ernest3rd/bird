#include "videoBuffer.h"

VideoBuffer::VideoBuffer(int width, int height, int first_pin, int reset_pin, int clock_pin){
  setup(width,height,first_pin,reset_pin,clock_pin);
}

void VideoBuffer::setup(int width, int height, int first_pin, int reset_pin, int clock_pin){
  this->width = width;
  this->height = height;
  this->reset_pin = reset_pin;
  this->clock_pin = clock_pin;

  refresh_rate = int(1000000/60.0/height);
  
  if(!row_pins){
    free(row_pins);
  }
  if(!vbuffer){
    free(vbuffer);
  }
    row_pins = (int *)malloc(sizeof(int) * height);
    vbuffer = (bool *)malloc(sizeof(bool) * width * height);
  
  for(int i=0; i<height; i++){
    row_pins[i] = first_pin + i;
    pinMode(first_pin + i, OUTPUT);
  }

  for(int i=0; i<width*height; i++){
    vbuffer[i] = false;  
  }
  
  pinMode(reset_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  
  reset();
}
  
void VideoBuffer::flush(){
  unsigned long m = micros();
  if(m<last_millis){
    last_millis = micros();
  }
  else if(m-last_millis >= refresh_rate){
    last_millis = m;
    advance();
  }
}

void VideoBuffer::lightRow(){
  for(int y=0; y<height; y++){
    digitalWrite(row_pins[height-1-y], LOW);
    if(vbuffer[current_row+y*width]){
      digitalWrite(row_pins[height-1-y],  HIGH);
    }
  }  
}

void VideoBuffer::dimRow(){
  for(int i=0; i<height; i++){
    digitalWrite(row_pins[i], LOW);
  }
}

void VideoBuffer::advance(){
  dimRow(); //disable to make smoother on emulator
  current_row++;
  digitalWrite(clock_pin, HIGH);
  digitalWrite(clock_pin, LOW);
  if(current_row > width-1){
    reset();
  }
  lightRow();
}

void VideoBuffer::reset(){
  digitalWrite(reset_pin, HIGH);
  digitalWrite(reset_pin, LOW);
  current_row = 0;
}

void VideoBuffer::setPixel(int x, int y, bool on){
  if(x >= 0 && x < width && y >= 0 && y < height){
    setPixel(y*width+x, on);
  }
}

void VideoBuffer::setPixel(int i, bool on){
  vbuffer[i] = on;
}

bool VideoBuffer::getPixel(int x, int y){
    return getPixel(y*width+x);
}

bool VideoBuffer::getPixel(int i){
    return vbuffer[i];
}

void VideoBuffer::clear(){
  for(int i=0; i<width*height; i++){
    setPixel(i, false);  
  }
}

