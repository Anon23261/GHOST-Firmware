#include "sensors.h"
#include <M5StickCPlus.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void initSensors() {
    if (!bmp.begin()) {
        Serial.println("Error: Could not find a valid BMP280 sensor, check wiring!");
        while (1);
    }
    
    // Configure sensor settings
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void readSensors() {
    static unsigned long lastRead = 0;
    
    if (millis() - lastRead >= SENSOR_UPDATE_INTERVAL) {
        lastRead = millis();
        
        float temperature = bmp.readTemperature();
        float pressure = bmp.readPressure() / 100.0F; // Convert to hPa
        float altitude = bmp.readAltitude(1013.25); // Adjust the sea level pressure as necessary
        
        if (isnan(temperature) || isnan(pressure) || isnan(altitude)) {
            Serial.println("Error: Failed to read sensor data");
            return;
        }
        
        Serial.print("Temperature = ");
        Serial.print(temperature);
        Serial.println(" *C");

        Serial.print("Pressure = ");
        Serial.print(pressure);
        Serial.println(" hPa");

        Serial.print("Approx. Altitude = ");
        Serial.print(altitude);
        Serial.println(" m");
        
        // Add battery level monitoring
        float battery = M5.getBatteryLevel();
        Serial.print("Battery Level = ");
        Serial.print(battery);
        Serial.println("%");
        
        // Check battery level
        if (battery < 20) {
            Serial.println("Warning: Low battery level!");
        }
    }
}
