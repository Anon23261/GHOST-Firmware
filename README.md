# GHOST-Firmware
M5Stick CPlus 1.1

## Project Description
GHOST-Firmware is a custom firmware for the M5Stick CPlus 1.1. The purpose of this project is to provide enhanced functionality and features for the M5Stick CPlus, including improved display handling, sensor integration, and communication capabilities.

## Setting Up the Development Environment
To set up the development environment for GHOST-Firmware, follow these steps:
1. Install the Arduino IDE from the official website: https://www.arduino.cc/en/software
2. Install the necessary board support package for M5Stick CPlus:
   - Open the Arduino IDE and go to `File` -> `Preferences`
   - In the `Additional Board Manager URLs` field, add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Go to `Tools` -> `Board` -> `Boards Manager` and search for `esp32`
   - Install the `esp32` package by Espressif Systems
3. Install the required libraries:
   - Go to `Sketch` -> `Include Library` -> `Manage Libraries`
   - Search for and install the following libraries:
     - `M5StickCPlus`
     - `Adafruit Sensor`
     - `Adafruit Unified Sensor`
     - `Adafruit GFX Library`
     - `Adafruit BusIO`

## Building and Flashing the Firmware
To build and flash the GHOST-Firmware onto your M5Stick CPlus, follow these steps:
1. Open the GHOST-Firmware project in the Arduino IDE
2. Select the correct board and port:
   - Go to `Tools` -> `Board` and select `M5Stick-C`
   - Go to `Tools` -> `Port` and select the appropriate port for your M5Stick CPlus
3. Compile the firmware:
   - Click on the `Verify` button (checkmark icon) to compile the firmware
4. Flash the firmware:
   - Click on the `Upload` button (right arrow icon) to flash the firmware onto your M5Stick CPlus

## Contributing
We welcome contributions to the GHOST-Firmware project! If you would like to contribute, please follow these guidelines:
1. Fork the repository and create a new branch for your feature or bugfix
2. Make your changes and ensure that the code compiles and runs correctly
3. Submit a pull request with a clear description of your changes and the problem they solve
4. Be responsive to feedback and be prepared to make revisions to your code if necessary

Thank you for contributing to GHOST-Firmware!
