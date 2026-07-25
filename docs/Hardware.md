# Hardware Design

## Overview

The hardware of the flight computer consists of a microcontroller, sensors, storage, and power management modules.

## Main Components

### ESP32-WROOM

The ESP32 serves as the primary processor for the flight computer.

**Responsibilities:**

- Sensor communication
- Data processing
- SD card data logging
- System control

### BNO055 IMU

The BNO055 provides orientation and motion data for the flight computer.

**Measurements:**

- Acceleration
- Gyroscope data
- Magnetic orientation
- Euler angles

### BMP388 Barometer

The BMP388 provides altitude estimation based on atmospheric pressure measurements.

**Measurements:**

- Pressure
- Temperature
- Altitude

### MicroSD Module

The MicroSD module stores flight telemetry data for post-flight analysis and evaluation.

### Power System

The electronics are powered using a LiPo battery with regulated voltage conversion to provide stable power to onboard components.

**Power System Goals:**

- Stable voltage supply
- Protection for sensitive electronics
- Efficient operation during flight
