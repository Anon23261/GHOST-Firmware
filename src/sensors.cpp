#include "sensors.h"
#include <M5StickCPlus.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void initSensors() {
    if (!bmp.begin()) {
        Serial.println("Could not find a valid BMP280 sensor, check wiring!");
        while (1);
    }
}

void readSensors() {
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bmp.readAltitude(1013.25)); // Adjust the sea level pressure as necessary
    Serial.println(" m");
}
