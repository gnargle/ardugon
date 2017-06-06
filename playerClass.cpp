#include <Arduboy2.h>

#define START_X 63;
#define START_Y 20;
#define CENTRE_X 64;
#define CENTRE_Y 32

class Player{
  public:
    float x = START_X;
    float x1 = x;
    float y = START_Y;
    float y1 = y;
    float theta = 0;
    bool rotateClock = false;
    bool rotateAnti = false;
    bool resetRound = false;


  void handleInput(Arduboy2 ab){
    if (ab.pressed(LEFT_BUTTON)){
      rotateAnti = true;
    }
    if (ab.pressed(RIGHT_BUTTON)){
      rotateClock = true;
    }
    if (ab.pressed(A_BUTTON)){
      resetRound = true;
    }
    if (ab.notPressed(LEFT_BUTTON)){
      rotateAnti = false;
    }
    if (ab.notPressed(RIGHT_BUTTON)){
      rotateClock = false;
    }
  }

  void draw(Arduboy2 ab, char* sprite){
    ab.drawBitmap(x,y,sprite,3,3,WHITE);
  }

  void updatePlayer(Arduboy2 ab){
    handleInput(ab);
    
    if (rotateAnti){
      theta = -0.1;
      x = x-CENTRE_X;
      y = y-CENTRE_Y;
      x1 = x*cos(theta)-y*sin(theta);
      y1 = y*cos(theta)+x*sin(theta);
      x = x1 + CENTRE_X;
      y = y1 + CENTRE_Y;
    }
    if (rotateClock){
      theta = 0.1;
      x = x-CENTRE_X;
      y = y-CENTRE_Y;
      x1 = x*cos(theta)-y*sin(theta);
      y1 = y*cos(theta)+x*sin(theta);
      x = x1 + CENTRE_X;
      y = y1 + CENTRE_Y;
    }

    ab.setCursor(0,0);
    char port[15];
    sprintf(port,"%d%d%d%f",rotateAnti,rotateClock,resetRound,theta);
    ab.print(port);
  }
};
