#include <stdio.h>
#include <wiringPi.h>
#define LED 13
int main(void)
{
	printf("OrangePi Blink...\r\n");
	wiringPiSetup();
	pinMode(LED, OUTPUT);
	while(1)
	{
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
}
