#include "../../archidea.h"
#define STM32F401CCU

u32 main()
{
	gpio_config config;
	config = gpio_driver::get_config(hardware.gpio.port_c, &config);
	config.pin[13].mode = gpio_mode::output;
	config = gpio_driver::set_config(hardware.gpio.port_c, &config);
}