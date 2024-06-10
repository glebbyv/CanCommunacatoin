# GoKart CAN Library
In this library, CAN communication is managed by a handler, which allows for hardware initialization, message reception and message transmission via CAN communication. The data bytes are stored in the object's attributes as an array.

## Features

- Initialize the MCP2515 CAN controller
- Send CAN messages
- Receive CAN messages
- Support for standard and extended CAN IDs

## External Libraries Used
- `mcp_can` (by coryjfowler): Library for interfacing with the MCP2515 CAN controller.
- `SPI`: Arduino SPI library for SPI communication.  


### Class Members
- `byte Data[8]`: An array of 8 bytes used to store the data received or to be sent over the CAN bus.
- `int CAN0_INT`: An integer representing the Arduino pin connected to the interrupt pin of the MCP2515 CAN controller.
- `int CS`: An integer representing the Arduino pin connected to the chip select pin of the MCP2515 CAN controller.
- `CAN`: A pointer to an instance of the `MCP_CAN` class for interacting with the MCP2515 CAN controller.

### Public Methods
- `GoKartCan(int CAN0_INT, int CS)`: Constructor method for initializing the CAN bus with specified interrupt and chip select pins.
- `void receive()`: Method for receiving CAN messages. It reads the message and prints its details to the serial monitor.
- `void send(int ID, int CAN_FRAME, int data_length)`: Sends the object instance's data array as a CAN message with the specified ID, frame type, and data length.
### Example

```cpp
#include "GoKartCan.h"
#include <Arduino.h>

GoKartCan CanHandler(2, 10); // Interrupt pin: 2, Chip select pin: 10

void setup() {
  Serial.begin(115200);
}

void loop() {
  CanHandler.receive(); // Check for and print any received CAN messages
  // Example of sending a message
  CanHandler.Data[0] = 0x01;
  CanHandler.Data[1] = 0x02;
  CanHandler.Data[2] = 0x03;
  CanHandler.Data[3] = 0x04;
  CanHandler.Data[4] = 0x05;
  CanHandler.Data[5] = 0x06;
  CanHandler.Data[6] = 0x07;
  CanHandler.Data[7] = 0x08;
  CanHandler.send(0x100, 0, 8); // Send a message with ID 0x100
  delay(1000);
}
