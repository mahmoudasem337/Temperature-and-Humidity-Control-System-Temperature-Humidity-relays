# Temperature-and-Humidity-Control-System-Temperature-Humidity-relays.

## 🚀 Project Overview
This project demonstrates a simple temperature-based automation system using an Arduino Uno, a DHT22 temperature and humidity sensor, and relay modules. It automates the control of devices (like LEDs) based on temperature readings.

## 🛠️ Key Features
- **Temperature Monitoring**: Reads temperature using the DHT22 sensor.
- **Relay Control**: Automates device switching based on temperature thresholds.
- **Visual Feedback**: LEDs provide status indicators for the relays.
- **Scalable Design**: Can be adapted for controlling multiple devices or appliances.

## 📜 How It Works
1. The **DHT22 sensor** reads the current temperature.
2. The Arduino processes the temperature data and compares it to preset thresholds.
3. Based on the threshold, the Arduino triggers the **relay modules** to control connected devices (e.g., turning on an LED).

## ⚡ Circuit Details
### Components Used
- **Arduino Uno**: The microcontroller board used to process the sensor data and control relays.
- **DHT22 Sensor**: For temperature and humidity measurement.
- **Relay Modules (x2)**: Switches to control external devices.
- **LEDs and Resistors**: Indicators for the relay status.
- **Jumper Wires**: For connections.

### Wiring Overview
1. **DHT22 Sensor**:
   - `VCC`: 5V on Arduino.
   - `GND`: GND on Arduino.
   - `Data`: Digital pin (Pin 2) on Arduino.

2. **Relay Modules**:
   - `VCC`: 5V on Arduino.
   - `GND`: GND on Arduino.
   - `IN`: Digital pins (Pin 3 and Pin 4) on Arduino.
   - **COM**: Connected to a power source (5V).
   - **NO**: Connected to the load (e.g., LED).

3. **LEDs**:
   - Anode (+): Connected to the relay's NO terminal.
   - Cathode (-): Connected through a resistor to ground.

## 📸 Circuit Diagram
![image](https://github.com/user-attachments/assets/06de2f05-f730-472a-8209-a83de2f9b5fb)


