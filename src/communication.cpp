#include "communication.h"
#include <Arduino.h>

void initCommunication() {
    Serial.begin(COMMUNICATION_BAUD_RATE);
    Serial.setTimeout(1000); // Set timeout for serial communication
    Serial.println("GHOST-Firmware Communication Initialized");
}

void handleCommunication() {
    static unsigned long lastReceive = 0;
    static String messageBuffer = "";
    
    if (Serial.available() > 0) {
        lastReceive = millis();
        char receivedChar = Serial.read();
        
        if (receivedChar == '\n') {
            if (!messageBuffer.isEmpty()) {
                processMessage(messageBuffer);
                messageBuffer = "";
            }
        } else {
            messageBuffer += receivedChar;
            
            // Prevent buffer overflow
            if (messageBuffer.length() > 255) {
                Serial.println("Error: Message too long, discarding");
                messageBuffer = "";
            }
        }
    }
    
    // Handle timeout
    if (millis() - lastReceive > 5000) {
        if (!messageBuffer.isEmpty()) {
            Serial.println("Warning: Message timeout, discarding");
            messageBuffer = "";
        }
    }
}

void processMessage(const String& message) {
    // Basic message validation
    if (message.length() < 3) {
        Serial.println("Error: Invalid message format");
        return;
    }
    
    // Extract command and parameters
    String command = message.substring(0, 3);
    String parameters = message.substring(3);
    
    // Process commands
    if (command == "GET") {
        // Handle GET requests
        if (parameters == "TEMP") {
            Serial.print("TEMP:");
            Serial.println(bmp.readTemperature());
        } else if (parameters == "PRESS") {
            Serial.print("PRESS:");
            Serial.println(bmp.readPressure() / 100.0F);
        } else if (parameters == "ALT") {
            Serial.print("ALT:");
            Serial.println(bmp.readAltitude(1013.25));
        } else if (parameters == "BATT") {
            Serial.print("BATT:");
            Serial.println(M5.getBatteryLevel());
        } else {
            Serial.println("Error: Unknown parameter");
        }
    } else if (command == "SET") {
        // Handle SET commands
        if (parameters.startsWith("TEMP:")) {
            // Example: SET TEMP:25.0
            float targetTemp = parameters.substring(5).toFloat();
            Serial.print("Setting target temperature to ");
            Serial.println(targetTemp);
            // Add temperature control logic here
        } else {
            Serial.println("Error: Unknown command");
        }
    } else {
        Serial.println("Error: Unknown command");
    }
}
