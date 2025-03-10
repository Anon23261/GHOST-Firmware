#include "utils.h"
#include <Arduino.h>

void printDebug(const char* message) {
    Serial.println(message);
}

void delayMilliseconds(unsigned long milliseconds) {
    delay(milliseconds);
}
