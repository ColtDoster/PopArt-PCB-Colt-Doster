#include <Adafruit_NeoPixel.h>
#include "frames.h"
#include <Bounce2.h>

Bounce but1 = Bounce();

Adafruit_NeoPixel strip (24, 0); //ACTUALLY INITIALIZE A PIN WHENEVER YOU WIRE UP

int colors [3][3] {
  {0, 0, 0},           // 0 black
  {255, 255, 255},     // 1 white
  {0, 0, 255},         // 2 blue

};

//initiaized timer variables that will help move animations along
long lastTime1 = 0;
long lastTime2 = 0;
long lastTime3 = 0;
long timer1 = 20;
long timer2 = 250;


// these values help keep up with what part of the animation we are on, and what color to assign them
int whichPixel = 1;
boolean whichColor = true;

//current state represents which animation is being shown
int currentState;

void setup() {
  strip.begin();
  strip.clear();
  strip.show();
  strip.setBrightness(255);

  but1.attach(1, INPUT);
  but1.interval(5);
  currentState = 0;

}

void loop() {
  but1.update();

  if (but1.rose()) {
    strip.clear();
    currentState = (currentState + 1) % 4 ;
    strip.clear();
  }

  //finite state machine
  switch (currentState) {

    case 0: off();  break;
    case 1: on();   break;
    case 2: simple_Animation(); break;
    case 3: mapped_Animation(); break;

  }

}

// is the off state NO LEDS SHOULD BE LIT
void off() {
  //strip.clear();
  for ( int i = 1; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);

  }
  strip.show();
}

// this is a static image state, THE TRACTOR SHOULD BE GREEN
void on() {
  for ( int j = 0; j < 24; j++) {
    strip.setPixelColor(j, 255, 255, 255);
    for ( int i = 1; i < 14; i++) {
      strip.setPixelColor(i, 0, 255, 0);

    }
  }
  strip.show();
}

// this is the simple animation state, THE TRACTOR SHOULD BE ALTERNATING RED AND CYAN
void simple_Animation() {

  strip.setPixelColor(0, 255, 255, 255);

  for ( int j = 14; j < 24; j++) {
    strip.setPixelColor(j, 255, 255, 255);
    strip.show();
  }

  if (millis() - lastTime1 > timer1) {
    lastTime1 = millis();
    if(whichColor){
    strip.setPixelColor(whichPixel, 255,0,0);
    } else {
    strip.setPixelColor(whichPixel, 0,255,255);  
    }
    whichPixel += 1;
    if(whichPixel == 14){
      whichPixel = 1;
      whichColor = !whichColor;
    }
  }

  strip.show();
}


// this is the mapped animation, it pulls the animation from "frames.h," IT SHOULD BE A BLUE TRACTOR WHERE THE WHEELS ARE ROTATING.
void mapped_Animation() {

  static int whichFrame = 0;

  for (int i = 0; i < 54; i++) {
    int pixAddress = pixelMap[i];
    int whichColor = animation[whichFrame][pixAddress];
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];

    if (pixAddress != -1) {
      strip.setPixelColor(pixAddress, red, green, blue);
    }

  }
  if(millis() - lastTime3 > timer2){
  strip.show();
  whichFrame = (whichFrame + 1) % 4;
  lastTime3 = millis();
  }
}
