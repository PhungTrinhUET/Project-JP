# Project-JP

# ESP32 DHT11 Sensor Data and LED Control with Blynk

This repository contains a program that allows an ESP32 to read temperature and humidity data using a DHT11 sensor and control an LED through the Blynk app. The program sends sensor data to the Blynk app and listens for a signal to control an LED connected to the ESP32.

## Purpose

The purpose of this project is to demonstrate how an ESP32 can interface with the Blynk platform to send sensor data and receive commands. It showcases real-time data monitoring and device control, which are fundamental aspects of IoT applications.

## How It Works

- The ESP32 reads temperature and humidity data from the DHT11 sensor.
- The data is sent to the Blynk app using virtual pins.
- The Blynk app displays the sensor data and allows the user to control an LED connected to the ESP32.

## Libraries and Installation
- ESP32: - File -> Preferences -> Enter the following into the “Additional Board Manager URLs” field: - https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
- Open the Boards Manager. Go to Tools > Board > Boards Manager…
- Search for ESP32 and press install button for the “ESP32 “:
- After searching for ESP32, please download the 2 ESP32 library versions shown in the image to your computer.
  ![image](https://github.com/PhungTrinhUET/Project-JP/assets/128596518/5b8ccfe0-daba-4524-9723-18d022430a3c)

# Install DHT Lib:
- Add lib: In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries. Search DHT sensor and install
![image](https://github.com/PhungTrinhUET/Project-JP/assets/128596518/8c3b3ffc-303d-483d-86ec-566f9a32b2cf)

# Install Blynk:
- Add lib: In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries. Search Blynk and install
![image](https://github.com/PhungTrinhUET/Project-JP/assets/128596518/6a6e0d43-8a69-46ba-8a0c-6556fddcdc0d)



- `WiFi.h`: To connect the ESP32 to the internet via Wi-Fi.
- `WiFiClient.h`: To create a client that can connect to a specified internet IP address and port.
- `BlynkSimpleEsp32.h`: To facilitate communication between the ESP32 and the Blynk platform.
- `DHT.h`: To read data from the DHT11 sensor.

You can install these libraries using the Arduino Library Manager in the Arduino IDE.

## Key Functions

- `sendSensor()`: Reads humidity and temperature data from the DHT11 sensor and sends it to the Blynk app.
- `setup()`: Initializes the serial communication, connects the ESP32 to Blynk, sets up the DHT sensor, configures the LED pin as output, and sets a timer to periodically send sensor data.
- `loop()`: Runs the Blynk and timer functions in a loop to maintain the program's functionality.
- `BLYNK_WRITE(V0)`: A callback function that is triggered when the virtual pin V0's state is changed in the Blynk app. It controls the LED based on the pin's value.

## Setup Instructions

1. Replace the placeholders in the code with your Wi-Fi credentials and Blynk Auth Token.
2. Connect the DHT11 sensor's data pin to GPIO 14 on the ESP32, VCC to 3.3V, and GND to ground.
3. Connect the LED's anode to GPIO 2 (D2-ESP32) through a resistor and the cathode to ground.
4. Upload the code to your ESP32.
5. Create a Blynk project with a gauge widget for temperature, a gauge widget for humidity, and a button widget for LED control.

## Contributing

Feel free to fork this repository, make improvements, and submit a pull request with your changes.

## License

This project is open-sourced under the MIT License. See the LICENSE file for more details.


