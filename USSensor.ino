#include "DistanceController.h"

const byte TRIGG_PIN = 12;
const byte ECHO_PIN = 14;
const byte RED_PIN = 25;
const byte YELLOW_PIN = 26;
const byte GREEN_PIN = 27;


DistanceController controller(TRIGG_PIN, ECHO_PIN, RED_PIN, YELLOW_PIN, GREEN_PIN);


void setup() {
  controller.init();
}

void loop() {
  controller.update();

}
