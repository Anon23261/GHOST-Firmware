#include <M5StickCPlus.h>
#include "config.h"
#include "utils.h"
#include "display.h"
#include "sensors.h"
#include "communication.h"

void setup() {
    M5.begin();
    initDisplay();
    initSensors();
    initCommunication();
}

void loop() {
    updateDisplay();
    readSensors();
    handleCommunication();
    delay(1000);
}