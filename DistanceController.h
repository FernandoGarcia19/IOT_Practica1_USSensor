#ifndef _DISTANCECONTROLLER_H_ 
#define _DISTANCECONTROLLER_H_

#include "Led.h"
#include "UltraSonicSensor.h"

class DistanceController {
private:
    UltraSonicSensor sensor;
    Led l_red, l_yellow, l_green;
    const long MAX_DIST_GREEN = 60.0;
    const long MAX_DIST_YELLOW = 40.0;
    const long MAX_DIST_RED = 20.0;

public:
    DistanceController(const byte& trigPin, const byte& echoPin, const byte& redPin, const byte& yellowPin, const byte& greenPin)
        : sensor(trigPin, echoPin), l_red(redPin), l_yellow(yellowPin), l_green(greenPin) {}

    void init() {
        sensor.init();
    }

    void update() {
        sensor.update();
        long distance = sensor.getDistanceCM();

        l_green.setState((distance > MAX_DIST_YELLOW && distance <= MAX_DIST_GREEN) ? Led::STATE_ON : Led::STATE_OFF);
        l_yellow.setState((distance > MAX_DIST_RED && distance <= MAX_DIST_YELLOW) ? Led::STATE_ON : Led::STATE_OFF);
        l_red.setState(distance <= MAX_DIST_RED ? Led::STATE_ON : Led::STATE_OFF);
    }
};

#endif // _DISTANCECONTROLLER_H_