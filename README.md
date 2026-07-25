# ESP32 Rocket Flight Computer

An open-source avionics system for logging flight data and enabling autonomous flight control for amateur rocketry.

## Overview

This project details the creation and implementation of a custom rocket flight computer utilizing an ESP32 microcontroller, multiple onboard sensors, and a custom PCB. This system records various real-time flight metrics:

- Altitude
- Acceleration
- Orientation
- Temperature
- Atmospheric pressure

Future iterations will incorporate a range of active flight control systems, including stabilization and autonomous descent control.

## Project Goals

The objectives guiding this project are:

- Design a custom rocket avionics system
- Develop embedded firmware for sensor acquisition and data logging
- Design and create a custom PCB incorporating flight components
- Collect and analyze real-world flight data
- Establish a framework for future autonomous flight capabilities

## Current Hardware

- ESP32-WROOM microcontroller
- Adafruit BNO055 9-axis IMU
- Adafruit BMP388 barometric pressure sensor
- MicroSD storage module
- LiPo battery power system
- Custom KiCad-designed PCB

## Project Status

**Current Phase:** Hardware Development and Testing

### Completed

- Sensor communication testing
- Initial firmware development
- Data logging system
- PCB schematic and layout design

### In Progress

- PCB manufacturing
- Hardware integration
- Flight test preparation

### Future

- Real-world flight data collection
- Optimization of the flight computer
- Active stabilization research

## Repository Structure
