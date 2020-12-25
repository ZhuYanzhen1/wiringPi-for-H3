#ifndef _MCP2515_COM_H_
#define _MCP2515_COM_H_

#define DUMMY_BYTE 0xff

///// EFLAG Command Byte /////
#define EWARN (0x01 << 0)
#define RXWAR (0x01 << 1)
#define TXWAR (0x01 << 2)
#define RXEP (0x01 << 3)
#define TXEP (0x01 << 4)
#define TXB0 (0x01 << 5)
#define RX0OVR (0x01 << 6)
#define RX1OVR (0x01 << 7)

///// TXBCTRL Command Byte /////
#define TXREQ 0x08  //Message Transmit Request
#define ABTF 0x40   //Message Transmit Abort

///// TXBDLC & RXBDLC Command Byte /////
#define RTR 0x40    //Remote Transmit Request

///// TXBSIDL & RXFSIDL Command Byte /////
#define EXIDE 0x08  //Extend ID Enable

///// RXBSIDL Command Byte /////
#define IDE 0x08    //Extend ID Flag
#define SRR 0x10    //Remote Transmit Flag

///// CANITE Command Byte /////
#define MERRF 0x80  //Message Error interrupt
#define WAKIF 0x40  //Wakeup interrupt
#define ERRIF 0x20  //Error interrupt
#define TX2IF 0x10  //Transmit Buffer 2 empty interrupt
#define TX1IF 0x08  //Transmit Buffer 1 empty interrupt
#define TX0IF 0x04  //Transmit Buffer 0 empty interrupt
#define RX1IF 0x02  //Receive Buffer 1 Full interrupt
#define RX0IF 0x01  //Receive Buffer 0 Full interrupt

///// CAN Mode /////
#define CAN_Config_Mode 0x80
#define CAN_Listen_Only_Mode 0x60
#define CAN_LoopBack_Mode 0x40
#define CAN_Sleep_Mode 0x20
#define CAN_Normal_Mode 0x00

///// MCP2515 Command Byte /////
#define CAN_RESET 0xc0
#define CAN_READ 0x03
#define CAN_WRITE 0x02

#endif
