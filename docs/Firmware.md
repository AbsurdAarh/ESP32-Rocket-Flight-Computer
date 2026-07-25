# Firmware

## Overview

The flight computer firmware is written in C++ using the Arduino framework. The firmware is responsible for communicating with onboard sensors, processing sensor data, and logging flight information to a storage system.

## Current Functionality

Implemented features include:

- BNO055 sensor communication
- BMP388 sensor communication
- Sensor calibration
- SD card data logging
- CSV-formatted telemetry output

## Data Logged

The following data is currently collected by the flight computer:

- Time
- Altitude
- Pressure
- Temperature
- Roll
- Pitch
- Yaw

## Firmware Improvements in Development

The firmware is under continuous development. Planned features and improvements include:

- Optimized sensor fusion
- Improved flight state identification
- Real-time flight telemetry
- Autonomous flight control implementation
