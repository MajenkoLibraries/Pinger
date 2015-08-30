#include <Pinger.h>

Pinger::Pinger(int trigpin, int echopin) {
    // Constructor code here
    _trigPin = trigpin;
    _echoPin = echopin;
    _divValue = 58.2;
}

float Pinger::ping() {
    pinMode(_trigPin, OUTPUT);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    uint32_t duration = pulseIn(_echoPin, HIGH);
    return (duration / _divValue);
}

void Pinger::setDivider(float d) {
    _divValue = d;
}
