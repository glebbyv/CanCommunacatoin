#ifndef GOKARTCAN_H
#define GOKARTCAN_H
#include <mcp_can.h>

class GoKartCan{

  public:
  GoKartCan(int CAN0_INT, int CS);
  unsigned char Data[8];
  void receive();
  void send(int ID, int CAN_FRAME,int data_length);

  private:
  int CAN0_INT,CS;
  MCP_CAN* CAN;

};

#endif