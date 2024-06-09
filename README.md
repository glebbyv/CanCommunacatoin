# GoKart CAN Library

This library provides a simple interface for using a CAN bus with an Arduino board to communicate with a GoKart. It consists of two files: `GoKartCan.h` and `GoKartCan.cpp`.
## Features

- Initialize the MCP2515 CAN controller
- Send CAN messages
- Receive CAN messages
- Support for standard and extended CAN IDs

## GoKartCan.h

### Overview
The `GoKartCan.h` header file defines a class `GoKartCan` for interacting with the CAN bus. It includes the necessary Arduino libraries and declares the class members and methods.

### Class Members
- `Data`: An array of 8 bytes used to store the data received or to be sent over the CAN bus.
- `CAN0_INT`: An integer representing the Arduino pin connected to the interrupt pin of the MCP2515 CAN controller.
- `CS`: An integer representing the Arduino pin connected to the chip select pin of the MCP2515 CAN controller.
- `CAN`: A pointer to an instance of the `MCP_CAN` class for interacting with the MCP2515 CAN controller.

### Public Methods
- `GoKartCan(int CAN0_INT, int CS)`: Constructor method for initializing the CAN bus with specified interrupt and chip select pins.
- `void receive()`: Method for receiving CAN messages. It reads the message and prints its details to the serial monitor.
- `void send(int ID, int CAN_FRAME, int data_length)`: Method for sending CAN messages with a specified ID, frame type, and data length.

## GoKartCan.cpp

### Overview
The `GoKartCan.cpp` source file implements the methods declared in `GoKartCan.h`. It includes the necessary Arduino libraries and provides the functionality to interact with the CAN bus.

### Constructor
- `GoKartCan::GoKartCan(int CAN0_INT, int CS)`: Constructor method for initializing the CAN bus with the specified interrupt and chip select pins. It configures the CAN controller and the interrupt pin.

### Public Methods
- `GoKartCan::receive()`: Method for receiving CAN messages. It checks if a message is available, reads it, and prints the message ID, type, and data bytes to the serial monitor.
- `GoKartCan::send(int ID, int CAN_FRAME, int data_length)`: Method for sending CAN messages. It sends a message with the specified ID, frame type, and data length using the data stored in the `Data` array.

## Usage
To use the GoKart CAN Library in your Arduino project, include the `GoKartCan.h` header file and `GoKartCan.cpp` source file in your project directory. Then, create an instance of the `GoKartCan` class with the appropriate interrupt and chip select pins. You can then call the `send()` and `receive()` methods to communicate over the CAN bus.

### Example

```cpp
#include "GoKartCan.h"
#include <Arduino.h>

GoKartCan goKartCan(2, 10); // Interrupt pin: 2, Chip select pin: 10

void setup() {
  Serial.begin(115200);
}

void loop() {
  goKartCan.receive(); // Check for and print any received CAN messages
  // Example of sending a message
  goKartCan.Data[0] = 0x01;
  goKartCan.Data[1] = 0x02;
  goKartCan.Data[2] = 0x03;
  goKartCan.Data[3] = 0x04;
  goKartCan.Data[4] = 0x05;
  goKartCan.Data[5] = 0x06;
  goKartCan.Data[6] = 0x07;
  goKartCan.Data[7] = 0x08;
  goKartCan.send(0x100, 0, 8); // Send a message with ID 0x100
  delay(1000);
}
