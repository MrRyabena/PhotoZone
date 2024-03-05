#include "settings.h"
#include <GyverPWM.h>
#include <EncButton.h>
#include <GRGB.h>

Button btn(4, INPUT, LOW);

GRGB strip(COMMON_ANODE, Rp, Gp, Bp);

uint8_t mode{};

void setup() {

  Serial.begin(9600);

  //pinMode(btnSIGpin, INPUT);

  pinMode(btnVCCpin, OUTPUT);
  pinMode(btnGNDpin, OUTPUT);

  digitalWrite(btnVCCpin, 1);
  digitalWrite(btnGNDpin, 0);

  // PWM_prescaler(3, 1);
  // PWM_prescaler(9, 1);
  // PWM_TMR1_8BIT();
}

void loop() {

  btn.tick();

  if (btn.click()) mode++;
  if (mode > 5) mode = 0;

  switch (mode) {
    case 0: redWheel(); break;
    case 1: colorWheel(); break;
    case 2: red(); break;
    case 3: green(); break;
    case 4: blue(); break;
    case 5: purple(); break;
    default: break;
  }
}

void sendColor() {
  Serial.print(strip.R);
  Serial.print(',');
  Serial.print(strip.G);
  Serial.print(',');
  Serial.print(strip.B);
  Serial.print(';');
}
