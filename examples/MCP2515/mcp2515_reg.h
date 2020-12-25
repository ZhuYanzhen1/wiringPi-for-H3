#ifndef _MCP2515_REGISTER_H_
#define _MCP2515_REGISTER_H_

#define MCP2515_BASE 0x00

///// Transmit Buffer Control Register /////
#define TXB0CTRL (MCP2515_BASE + 0x30)
#define TXB1CTRL (MCP2515_BASE + 0x40)
#define TXB2CTRL (MCP2515_BASE + 0x50)

///// Transmit Request Configure Register /////
#define TXRTSCTRL (MCP2515_BASE + 0x0d)

///// Transmit Standard ID Register /////
#define TXB0SIDH (MCP2515_BASE + 0x31)
#define TXB0SIDL (MCP2515_BASE + 0x32)
#define TXB1SIDH (MCP2515_BASE + 0x41)
#define TXB1SIDL (MCP2515_BASE + 0x42)
#define TXB2SIDH (MCP2515_BASE + 0x51)
#define TXB2SIDL (MCP2515_BASE + 0x52)

///// Transmit Extend ID Register /////
#define TXB0EID8 (MCP2515_BASE + 0x33)
#define TXB0EID0 (MCP2515_BASE + 0x34)
#define TXB1EID8 (MCP2515_BASE + 0x43)
#define TXB1EID0 (MCP2515_BASE + 0x44)
#define TXB2EID8 (MCP2515_BASE + 0x53)
#define TXB2EID0 (MCP2515_BASE + 0x54)

///// Transmit Data Length Register /////
#define TXB0DLC (MCP2515_BASE + 0x35)
#define TXB1DLC (MCP2515_BASE + 0x45)
#define TXB2DLC (MCP2515_BASE + 0x55)

///// Transmit Data Base Address Register /////
#define TXB0D_BASE (MCP2515_BASE + 0x36)
#define TXB1D_BASE (MCP2515_BASE + 0x46)
#define TXB2D_BASE (MCP2515_BASE + 0x56)

///// Receive Buffer Control Register /////
#define RXB0CTRL (MCP2515_BASE + 0x60)
#define RXB1CTRL (MCP2515_BASE + 0x70)

///// Receive Control & Status Register /////
#define BFPCTRL (MCP2515_BASE + 0x0c)

///// Receive Standard ID Register /////
#define RXB0SIDH (MCP2515_BASE + 0x61)
#define RXB0SIDL (MCP2515_BASE + 0x62)
#define RXB1SIDH (MCP2515_BASE + 0x71)
#define RXB1SIDL (MCP2515_BASE + 0x72)

///// Receive Extend ID Register /////
#define RXB0EID8 (MCP2515_BASE + 0x63)
#define RXB0EID0 (MCP2515_BASE + 0x64)
#define RXB1EID8 (MCP2515_BASE + 0x73)
#define RXB1EID0 (MCP2515_BASE + 0x74)

///// Receive Data Length Register /////
#define RXB0DLC (MCP2515_BASE + 0x65)
#define RXB1DLC (MCP2515_BASE + 0x75)

///// Receive Data Base Address Register /////
#define RXB0D_BASE (MCP2515_BASE + 0x66)
#define RXB1D_BASE (MCP2515_BASE + 0x76)

//// Receive Standard ID Filter Register /////
#define RXF0SIDH (MCP2515_BASE + 0x00)
#define RXF0SIDL (MCP2515_BASE + 0x01)
#define RXF1SIDH (MCP2515_BASE + 0x04)
#define RXF1SIDL (MCP2515_BASE + 0x05)
#define RXF2SIDH (MCP2515_BASE + 0x08)
#define RXF2SIDL (MCP2515_BASE + 0x09)
#define RXF3SIDH (MCP2515_BASE + 0x10)
#define RXF3SIDL (MCP2515_BASE + 0x11)
#define RXF4SIDH (MCP2515_BASE + 0x14)
#define RXF4SIDL (MCP2515_BASE + 0x15)
#define RXF5SIDH (MCP2515_BASE + 0x18)
#define RXF5SIDL (MCP2515_BASE + 0x19)

///// Receive Extend ID Filter Register /////
#define RXF0EID8 (MCP2515_BASE + 0x02)
#define RXF0EID0 (MCP2515_BASE + 0x03)
#define RXF1EID8 (MCP2515_BASE + 0x06)
#define RXF1EID0 (MCP2515_BASE + 0x07)
#define RXF2EID8 (MCP2515_BASE + 0x0a)
#define RXF2EID0 (MCP2515_BASE + 0x0b)
#define RXF3EID8 (MCP2515_BASE + 0x12)
#define RXF3EID0 (MCP2515_BASE + 0x13)
#define RXF4EID8 (MCP2515_BASE + 0x16)
#define RXF4EID0 (MCP2515_BASE + 0x17)
#define RXF5EID8 (MCP2515_BASE + 0x1a)
#define RXF5EID0 (MCP2515_BASE + 0x1b)

///// Receive Standard ID Mask Register /////
#define RXM0SIDH (MCP2515_BASE + 0x20)
#define RXM0SIDL (MCP2515_BASE + 0x21)
#define RXM1SIDH (MCP2515_BASE + 0x24)
#define RXM1SIDL (MCP2515_BASE + 0x25)

///// Receive Extend ID Mask Register /////
#define RXM0EID8 (MCP2515_BASE + 0x22)
#define RXM0EID0 (MCP2515_BASE + 0x26)
#define RXM1EID8 (MCP2515_BASE + 0x23)
#define RXM1EID0 (MCP2515_BASE + 0x27)

///// Configure Register /////
#define CNF1 (MCP2515_BASE + 0x2a)
#define CNF2 (MCP2515_BASE + 0x29)
#define CNF3 (MCP2515_BASE + 0x28)

///// Transmit Error Counter Register /////
#define TEC (MCP2515_BASE + 0x1c)
///// Receive Error Counter Register /////
#define REC (MCP2515_BASE + 0x1d)
///// Error Flag Register /////
#define EFLG (MCP2515_BASE + 0x2d)
///// Interrupt Enable Register /////
#define CANINTE (MCP2515_BASE + 0x2b)
///// Interrupt Flag Register /////
#define CANINTF (MCP2515_BASE + 0x2c)
///// CAN Control Register /////
#define CANCTRL (MCP2515_BASE + 0x0f)
///// CAN Status Register /////
#define CANSTAT (MCP2515_BASE + 0x02)

#endif

