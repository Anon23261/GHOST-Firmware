#include "display.h"
#include <M5StickCPlus.h>

void initDisplay() {
    M5.Lcd.begin();
    M5.Lcd.setRotation(DISPLAY_ROTATION);
    M5.Lcd.fillScreen(BLACK);
}

void updateDisplay() {
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.print("Hello, GHOST-Firmware!");
}
