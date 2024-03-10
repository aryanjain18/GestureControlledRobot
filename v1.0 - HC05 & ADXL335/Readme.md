# Gesture Controlled Car with Arduino & Bluetooth

## Overview
This Arduino project allows you to control a car wirelessly using a Bluetooth HC-05 module. 
The car movements (forward, backward, left, right, stop) are controlled through Bluetooth commands sent from a paired device.
The movements are generated from a Accelerometer sensor.

## Hardware Requirements
- Arduino board
- ADXL335 accelerometer
- 2 x HC-05 Bluetooth modules
- L298N Motor Driver
- LED for status indication
- Chassis, motors, and wheels for the car
- Power source for the motors

## Circuit Connections
### Bluetooth HC-05
- HC-05 TX pin to Arduino RX pin (pin 0)
- HC-05 RX pin to Arduino TX pin (pin 1)
- HC-05 VCC pin to Arduino 5V
- HC-05 GND pin to Arduino GND

### ADXL335 Accelerometer
- Connect the accelerometer X and Y output pins to Arduino analog pins A0 and A1 respectively.
- Connect the accelerometer VCC pin to Arduino 3.3V.
- Connect the accelerometer GND pin to Arduino GND.

### L298N Motor Driver
- Connect the motor driver IN1, IN2, IN3, and IN4 pins to Arduino digital pins 7, 6, 5, and 4, respectively.
- Connect the motor driver OUT1, OUT2, OUT3, and OUT4 pins to the motors.

### LED Indicator
- Connect the LED to digital pin 13 for status indication.

## Arduino Code
The Arduino code (`BluetoothCarControl.ino`) interprets Bluetooth commands and controls the motors accordingly. It also uses the LED to indicate the status of the car.

## Motor Movement Functions
- `carForward()`: Move the car forward.
- `carBackward()`: Move the car backward.
- `carLeft()`: Turn the car left.
- `carRight()`: Turn the car right.
- `carStop()`: Stop the car.

## Bluetooth Commands
- `F`: Forward
- `B`: Backward
- `L`: Left
- `R`: Right
- `S`: Stop

## Pairing HC-05 Modules Using AT Commands
1. **Connect the HC-05 to Arduino:** Connect one HC-05 module to the Arduino board using the specified connections.
2. **Upload the "BluetoothCarControl.ino" sketch:** Use the Arduino IDE to upload the code to the Arduino board.
3. **Open the Serial Monitor:** Open the Arduino IDE Serial Monitor to view the debug messages.
4. **Configure AT Mode:** Enter AT command mode by sending "AT" through the Serial Monitor. You should receive an "OK" response.
7. **Set Device as Master/Slave:** Use "AT+ROLE" to set the device as Master (`AT+ROLE=1`) or Slave (`AT+ROLE=0`).
8. **Pair Devices:** Pair the two HC-05 modules by setting one as Master and the other as Slave. Use the "AT+BIND" command to bind their addresses.


