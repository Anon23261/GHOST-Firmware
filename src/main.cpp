#include <M5StickCPlus.h>
#include "src/config.h"
#include "src/utils.h"
#include "src/display.h"
#include "src/sensors.h"
#include "src/communication.h"

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