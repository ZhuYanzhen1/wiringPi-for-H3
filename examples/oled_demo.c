#include <stdio.h>
#include "oled.h"
#include "font.h"

int main(int argc, char **argv) {
	int e,i;
	char buf[100];
	struct display_info disp;
	disp.address = OLED_I2C_ADDR;
	disp.font = font2;
	e = oled_open(&disp, "/dev/i2c-0");
	oled_clear(&disp);
	oled_putstrto(&disp, 0, 8, "AcmeTech H3");

	disp.font = font1;
	oled_putstrto(&disp, 0, 16, "This Is Font1");

	disp.font = font2;
	oled_putstrto(&disp, 0, 24, "This Is Font2");
	//oled_putstrto(&disp, 0, 36+4, "");
	//oled_putstrto(&disp, 0, 45+5, "");

	disp.font = font3;
	oled_putstrto(&disp, 0, 36, "This Is Font3");

	oled_send_buffer(&disp);

	disp.font = font3;
	for (i = 0; i < 100; i++) {
		sprintf(buf, "Spnd spd  %d rpm", i);
		oled_putstrto(&disp, 0, 0, buf);
		oled_putstrto(&disp, 135-i, 36+4, "===");
		oled_putstrto(&disp, 100, 0+i/2, ".");

		oled_send_buffer(&disp);
	}
	return 0;
}
