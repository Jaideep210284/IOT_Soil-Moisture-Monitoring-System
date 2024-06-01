# Soil Moisture Monitoring System
This project is a soil moisture monitoring system that uses an analog soil moisture sensor, a relay, and an I2C LCD display to monitor and display the soil moisture level and control a water pump. The system provides real-time updates on the soil moisture status and automatically turns the water pump on or off based on the moisture level.

Table of Contents
Overview
Hardware Required
Software Required
Circuit Diagram
Installation
Usage
Code
Contributing
License
Contact
Overview
The soil moisture monitoring system reads the moisture level from a soil moisture sensor and displays the status on an LCD screen. Depending on the moisture level, the system can control a relay to turn a water pump on or off, ensuring that plants receive the right amount of water.

Hardware Required
Arduino Uno or compatible microcontroller
Soil moisture sensor
Relay module
I2C LCD display (16x2)
Jumper wires
Breadboard (optional)
Water pump (optional)
Software Required
Arduino IDE
LiquidCrystal_I2C library
Circuit Diagram
 (Note: Add a link to your circuit diagram image)

Installation
Clone the Repository:

bash
Copy code
git clone https://github.com/yourusername/soil-moisture-monitoring-system.git
cd soil-moisture-monitoring-system
Install the Required Libraries:
Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries and install the LiquidCrystal_I2C library.

Connect the Hardware:
Follow the circuit diagram to connect the soil moisture sensor, relay module, and I2C LCD display to the Arduino.

Usage
Upload the Code:
Open the soil_moisture_monitor.ino file in the Arduino IDE and upload it to your Arduino board.

Monitor the Soil Moisture:
The LCD display will show the current soil moisture status:

Soil Dry: If the soil moisture level is low, the relay will activate, turning the water pump on.
Soil Medium: If the soil moisture level is medium, the relay will deactivate, turning the water pump off.
Soil Wet: If the soil moisture level is high, the relay will deactivate, turning the water pump off.
