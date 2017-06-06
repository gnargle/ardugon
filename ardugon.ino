#include <Arduboy2.h>
#include <Arduboy2Core.h>
#include "globals.h"
#include "image_data.h"
#include "playerClass.cpp"

Player playerObj;

void setup() {
  // put your setup code here, to run once:
  ab.begin();
  ab.setFrameRate(60);
}

void loop() {
  if(!(ab.nextFrame()))
    return;
  // put your main code here, to run repeatedly:
  ab.clear();
  playerObj.updatePlayer(ab);
  playerObj.draw(ab, playerSpr);
  ab.display();
}
