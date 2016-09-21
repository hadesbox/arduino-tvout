#include "TVout.h"

#define SW_CTRL1 5
#define SW_CTRL2 6

#define SELECT_OSD {digitalWrite(SW_CTRL1, HIGH);digitalWrite(SW_CTRL2, HIGH);}
#define SELECT_A {digitalWrite(SW_CTRL1, LOW);  digitalWrite(SW_CTRL2, HIGH);}
#define SELECT_B {digitalWrite(SW_CTRL1, HIGH);  digitalWrite(SW_CTRL2, LOW);}

TVout TV;

void setup() {
  //video out init
  pinMode(SW_CTRL1, OUTPUT);
  pinMode(SW_CTRL2, OUTPUT);

  SELECT_OSD;
  TV.begin(PAL);
  TV.clear_screen();
  TV.draw_rect(0,0,8,8,WHITE);
  //TV.draw_row(0, 0, 7, WHITE);
  TV.set_pixel(2, 1, WHITE);
  TV.set_pixel(4, 1, WHITE);
  TV.set_pixel(6, 1, WHITE);
  TV.draw_rect(10,10,10,10,WHITE,WHITE);
  TV.draw_rect(10,10,10,10,WHITE,INVERT);
}

void loop() {
  TV.delay(1000);
}
