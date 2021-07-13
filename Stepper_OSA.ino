#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 15, 14, 16, 17);

int stepCount = 1;
int dir = 1;

void setup() {
  // TX:GP0, RX:GP1
  Serial1.setTX(0);  
  Serial1.setRX(1);
  Serial1.begin(115200);
}

void loop() {
  myStepper.step(dir * 360);
  myStepper.setSpeed(100);
  Serial1.print("steps: ");
  Serial1.println(stepCount * dir);
  stepCount++;

  if (stepCount > 1) {
    dir = dir * -1   ;
    stepCount = 1;
  }
  delay(300);
}

