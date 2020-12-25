#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "mcp2515_reg.h"
#include "mcp2515_com.h"
#include "mcp2515.h"

unsigned char SPI_ReadWrite(unsigned char buffer)
{
	unsigned char Result = buffer;
	wiringPiSPIDataRW(0, &buffer, 1);
	return Result;
}
unsigned char CAN_Read(unsigned char address)
{
	unsigned char Result;
	piLock(0);
	digitalWrite(MCP2515_CS1, 0);
	SPI_ReadWrite(CAN_READ);
	SPI_ReadWrite(address);
	Result = SPI_ReadWrite(DUMMY_BYTE);
	digitalWrite(MCP2515_CS1, 1);
	piUnlock(0);
	return Result;
}
void CAN_Write(unsigned char address, unsigned char buffer)
{
	piLock(0);
	digitalWrite(MCP2515_CS1, 0);
	SPI_ReadWrite(CAN_WRITE);
	SPI_ReadWrite(address);
	SPI_ReadWrite(buffer);
	digitalWrite(MCP2515_CS1, 1);
	piUnlock(0);
}

PI_THREAD (MCP2515_EXIT1)
{
	while(1)
	{
		delay(2);
		if(digitalRead(MCP2515_INT1) == 0)
			printf("GPIO%d Interrupt!!!\r\n", MCP2515_INT1);
	}
}

int main(int argc, char **argv)
{
	printf("hello world!!!\r\n");
	fflush(stdout);
	MCP2515_Init();
	return 0;
}
void MCP2515_MspInit(void)
{
	wiringPiSetup();
	pinMode(MCP2515_INT1, INPUT);
	pullUpDnControl(MCP2515_INT1, PUD_UP);
	//piThreadCreate(MCP2515_EXIT1);
	wiringPiSPISetup(MCP2515_SPI, SPI_Speed);
	pinMode(MCP2515_CS1, OUTPUT);
	digitalWrite(MCP2515_CS1, 1);
}
bool MCP2515_Init(struct CAN_InitTypeDef *CAN_InitSturcture)
{
	unsigned char tmp_num = 0;
	unsigned char tmp_reg = 0;
	if((CAN_InitSturcture->Prescaler % 2) != 0)
	{
		printf("\033[31m[Error]\033[0mPrescaler must be a multiple of two");
		return False;
	}
	if(CAN_InitSturcture->Prescaler == 0)
	{
		printf("\033[31m[Error]\033[0mPrescaler must be greater than two");
		return False;
	}
	if(CAN_InitSturcture->SJW_Length < 1)
	{
		printf("\033[31m[Error]\033[0mSynchronization Jump Width must be greater than one");
		return False;
	}
	if(CAN_InitSturcture->PS_Length < 1)
	{
		printf("\033[31m[Error]\033[0mPropagation Segment must be greater than one");
		return False;
	}
	if(CAN_InitSturcture->PS1_Length < 1)
	{
		printf("\033[31m[Error]\033[0mPS1 must be greater than one");
		return False;
	}
	if(CAN_InitSturcture->PS2_Length < 2)
	{
		printf("\033[31m[Error]\033[0mPS2 must be greater than two");
		return False;
	}
	MCP2515_MspInit();
	digitalWrite(MCP2515_CS1, 0);
	SPI_ReadWrite(CAN_RESET);
	digitalWrite(MCP2515_CS1, 1);
	do
	{
		tmp_num = CAN_Read(CANSTAT) & CAN_Config_Mode;
	}
	while(tmp_num != CAN_Config_Mode);
	tmp_reg = ((CAN_InitSturcture->SJW_Length - 1) & 0x03) << 6;
	tmp_reg |= (((CAN_InitSturcture->Prescaler / 2) - 1) & 0x1f);
	CAN_Write(CNF1, tmp_reg);
	tmp_reg = (0x80 | (((CAN_InitSturcture->PS1_Length - 1) & 0x07) << 3));
	tmp_reg |= ((CAN_InitSturcture->PS_Length - 1) & 0x07);
	CAN_Write(CNF2, tmp_reg);
	tmp_reg = ((CAN_InitSturcture->Wakeup_Filter & 0x01) << 7);
	tmp_reg |= ((CAN_InitSturcture->PS2_Length - 1) & 0x07);
	CAN_Write(CNF3, tmp_reg);
	CAN_Write(TXRTSCTRL, 0x00);

	CAN_Write(RXF0SIDH, 0x00);
	CAN_Write(RXF0SIDL, 0x00 | EXIDE);
	CAN_Write(RXF0EID8, 0x00);
	CAN_Write(RXF0EID0, 0x00);

	
}
