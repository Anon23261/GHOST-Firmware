#include "display.h"
#include <M5StickCPlus.h>

void initDisplay() {
    if (!M5.Lcd.begin()) {
        Serial.println("Error: Failed to initialize display");
        while (1); // Halt if display fails to initialize
    }
    M5.Lcd.setRotation(DISPLAY_ROTATION);
    M5.Lcd.fillScreen(BLACK);
}

void updateDisplay() {
    static unsigned long lastUpdate = 0;
    static int displayState = 0;
    
    if (millis() - lastUpdate >= 1000) { // Update every second
        lastUpdate = millis();
        
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setTextSize(2);
        
        switch (displayState) {
            case 0:
                M5.Lcd.print("GHOST-Firmware");
                break;
            case 1:
                M5.Lcd.print("System Running");
                break;
            case 2:
                M5.Lcd.print("Battery: ");
                M5.Lcd.print(M5.getBatteryLevel());
                M5.Lcd.print("%");
                break;
        }
        
        displayState = (displayState + 1) % 3;
    }
}
