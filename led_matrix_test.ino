#include <string.h>
#include "wall.h"
#include "hero.h"
#include "videoBuffer.h"
#include "charDrawer.h"

#define RESET 3
#define CLOCK 4
#define BUTTON 2
#define HEIGHT 8
#define WIDTH 10

#define GAME_TITLE 0
#define GAME_ACTION 1
#define GAME_CRASH 2
#define GAME_OVER 3
#define GAME_SCORE 4


VideoBuffer vb = VideoBuffer((int)WIDTH, (int)HEIGHT, 6, (int)RESET, (int)CLOCK);
unsigned long last_millis = 0;

Hero hero;
Wall wall;
bool button_down = false;
bool button_pressed = false;

int game_state = GAME_TITLE;
unsigned long game_state_changed = 0;

char title_text[5] = "BIRD";
char game_over_text[10] = "GAME OVER";
char score_text[6] = "SCORE";
char score[12];

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);

  hero.setup(1, HEIGHT/2);
  wall.setup(WIDTH, HEIGHT);

  last_millis = millis();
}

void loop(){
  unsigned long mls = millis();
    float delta = (mls-last_millis)/60.0;
    last_millis = mls;
    unsigned int length = 0;
    
    vb.clear();
    
    
    switch(game_state){
        case GAME_ACTION:
            wall.update(delta);
            hero.update(delta, digitalRead(BUTTON) == HIGH);
            if(hero.testCollision(&wall)){
                strcpy(score, score_text);
                sprintf(score, "%d", wall.getLevel()-1);
                gameAdvance();
            }
            wall.draw(&vb);
            hero.draw(&vb);
            break;
        case GAME_CRASH:
            if(mls-game_state_changed > 500 || mls % 100 < 50){
                for(int y=0; y<HEIGHT; y++){
                    for(int x=0; x<WIDTH; x++){
                        vb.setPixel(x, y, true);
                    }
                }
                wall.draw(&vb, true);
                hero.draw(&vb, true);
            }
            else {
                wall.draw(&vb);
                hero.draw(&vb);
            }
            if(mls-game_state_changed > 1500){
                gameAdvance();
            }
            break;
        case GAME_OVER:
            length = stringLengthInPixels(game_over_text) + WIDTH;
            drawString(game_over_text, WIDTH-int(((mls-game_state_changed)/200) % length), 2, &vb);
            if(button_pressed){
                gameAdvance();
            }
            break;
        case GAME_SCORE:
            length = stringLengthInPixels(score) + WIDTH;
            drawString(score, WIDTH-int(((mls-game_state_changed)/200) % length), 2, &vb);
            if(button_pressed){
                gameAdvance();
            }
            break;
        case GAME_TITLE:
        default:
            length = stringLengthInPixels(title_text) + WIDTH;
            drawString(title_text, WIDTH-int(((mls-game_state_changed)/200) % length), 2, &vb);
            if(button_pressed){
                gameAdvance();
            }
            break;
    }
    
    
    
    vb.flush();

    button_pressed = false;

    if(!button_down){
      if(digitalRead(BUTTON) == HIGH){
        button_down = true;
      }
    }
    else {
      if(digitalRead(BUTTON) == LOW){
        button_down = false;
        button_pressed = true;
      }
    }
}

void gameAdvance(){
    if(++game_state > GAME_SCORE){
        game_state = GAME_TITLE;
    }
    if(game_state == GAME_ACTION){
        hero.reset();
        wall.reset();
    }
    game_state_changed = millis();
}
