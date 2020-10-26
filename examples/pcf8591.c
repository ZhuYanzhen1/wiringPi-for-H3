#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define ADDRESS 0x48
#define BASE 64
#define A0 (BASE + 0)
#define A1 (BASE + 1)
#define A2 (BASE + 2)
#define A3 (BASE + 3)

#define UPTHREAHOLD 200
#define LOWTHREAHOLD 90

static unsigned char Delayxms = 5;
static unsigned int counter = LOWTHREAHOLD;

PI_THREAD (BreathLED)
{
	while(1)
	{
		counter = counter + 1;
		analogWrite(A0, counter);
		delay(Delayxms);
		if(counter == UPTHREAHOLD)
		{
			while(1)
			{
				counter = counter - 1;
				analogWrite(A0, counter);
				delay(Delayxms);
				if(counter == LOWTHREAHOLD)
					break;
			}
		}
	}
}

int main(int argc, char **argv)
{
	wiringPiSetup();
	pcf8591Setup(BASE, ADDRESS, "/dev/i2c-0");
	piThreadCreate(BreathLED);
	while(1)
	{
		printf("A0 Value:\033[31m%.2f\033[0m\r\n", ((analogRead(A0) * 5.0f) / 256.0f));
		printf("A1 Value:\033[31m%.2f\033[0m\r\n", ((analogRead(A1) * 5.0f) / 256.0f));
		printf("A2 Value:\033[31m%.2f\033[0m\r\n", ((analogRead(A2) * 5.0f) / 256.0f));
		printf("A3 Value:\033[31m%.2f\033[0m\r\n", ((analogRead(A3) * 5.0f) / 256.0f));
		printf("AOUT Value:\033[31m%.2f\033[0m", ((counter * 5.0f) / 256.0f));
		printf("\r\033[4A");
		fflush(stdout);
		delay(200);
	}
}

