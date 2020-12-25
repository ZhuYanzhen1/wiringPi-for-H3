#ifndef _MCP2515_H_
#define _MCP2515_H_

#define MCP2515_CS1 15
#define MCP2515_INT1 13
#define MCP2515_SPI 0
#define SPI_Speed 2000000

#define ENABLE 1
#define DISABLE 0

struct CAN_Package
{
    unsigned char SID;
    unsigned char DLC;
    unsigned char Data[8];
};

struct CAN_InitTypeDef
{
    unsigned char OSC_Freq;     //Oscillator Frequency (Unit: MHz)
    unsigned char Prescaler;    //Baudrate Prescaler(must be even and greater than 2)
    unsigned char SJW_Length;   //Synchronization Jump Width Length
    unsigned char PS_Length;    //Propagation Segment Length
    unsigned char PS1_Length;   //PS1 Length
    unsigned char PS2_Length;   //PS2 Length
    unsigned char Wakeup_Filter;//Enable or Disable wakeup filter
    void (*Receve_Callback)(struct CAN_Package);
};

bool MCP2515_Init(struct CAN_InitTypeDef *CAN_InitSturcture);

#endif
