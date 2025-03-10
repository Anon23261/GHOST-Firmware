#include "communication.h"
#include <Arduino.h>

void initCommunication() {
    Serial.begin(COMMUNICATION_BAUD_RATE);
}

void handleCommunication() {
    if (Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        processMessage(message);
    }
}

void processMessage(const String& message) {
    // Process the received message
    // Add your custom message handling code here
}
