# AQSU: Autonomous Aquatic Sediment Utility
Software for the AQSU autonomous robotic complex, designed for monitoring and cleaning organic sediment in freshwater bodies.
## Overview
The AQSU project is a system based on the ESP32 microcontroller that manages an autonomous catamaran. The system handles navigation, collects data on bottom conditions (turbidity, depth), and controls an automated manipulator for collecting organic sediment (sapropel).
## Key Features
* **Autonomous Navigation:** Heading and orientation stabilization using a 6-axis MEMS sensor (MPU6050).
* **Sensor Analytics:** Real-time collection and processing of turbidity and depth sensor data.
* **Actuator Control:** Integrated control of water-jet thrusters (via PWM) and the servo-driven manipulator.
* **Automated Cycle:** Intelligent algorithm for detecting contamination zones and executing the automated biomass collection cycle.
## Tech Stack
* **Hardware:** ESP32 NodeMCU, MPU6050, turbidity/depth sensors.
* **Firmware:** C++ (Arduino IDE/PlatformIO).
* **Libraries:**
* `ESP32Servo` — for manipulator actuator control.
* `Adafruit_MPU6050` — for gyroscope/accelerometer operations.
## Setup
1. Clone the repository: `git clone https://github.com/yourusername/aqsu.git`.
2. Open the project in PlatformIO or Arduino IDE.
3. Install the required dependencies from the PlatformIO Registry.
4. Configure the pin assignments in `config.h` according to your wiring diagram.
5. Upload the sketch to the ESP32.
