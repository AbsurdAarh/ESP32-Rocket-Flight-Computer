# Hardware

This folder contains all hardware-related documentation for the ESP32 Rocket Flight Computer, including component descriptions, datasheets, and the Bill of Materials (BOM).

## Hardware Overview

The hardware architecture consists of three primary subsystems:

- Processing
- Data Storage
- Power Management

These subsystems work together with an array of sensors to acquire, process, and store flight data throughout each mission.

## Processing

The flight computer is built around an **ESP32-WROOM** microcontroller, which serves as the central processor for the avionics system.

The ESP32 is responsible for:

- Communicating with onboard sensors
- Processing flight data
- Managing data logging to the SD card
- Controlling overall flight computer operation

The complete list of sensors and supporting electronics can be found in the **Bill of Materials**.

## Data Storage

Flight data is stored on a MicroSD card using a dedicated MicroSD module. Logged telemetry can be retrieved after flight for analysis, visualization, and system evaluation.

## Power Management

The power system distributes regulated power to all onboard electronics.

The system consists of:

- LiPo battery
- Linear voltage regulators
- DC-DC converters
- Voltage level translation circuits
- Power distribution circuitry

These components provide the required operating voltages for the ESP32, sensors, and other onboard modules while maintaining stable and reliable operation throughout flight.

## Bill of Materials

A detailed Bill of Materials (BOM) is provided in this folder. It includes the components selected for this project, along with their specifications and purpose within the flight computer.

The BOM is intended to help others understand, reproduce, or build upon this project.
