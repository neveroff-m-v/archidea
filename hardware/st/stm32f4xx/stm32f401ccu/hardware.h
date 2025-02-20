/**
* \brief hardware register
*/
struct hardware_reg
{
	/// reset and clock control (rcc)
	rcc_reg* rcc = (rcc_reg*) register_map::rcc;

	/// flash
	flash_reg* flash = (flash_reg*) register_map::flash_r;

	struct hardware_dma_reg
	{
		struct hardware_dma_port_reg
		{
			dma_reg* common = (dma_reg*) register_map::dma_1;

			dma_stream_reg* stream_0;

			dma_stream_reg* stream_1;

			dma_stream_reg* stream_2;

			dma_stream_reg* stream_3;

			dma_stream_reg* stream_4;

			dma_stream_reg* stream_5;

			dma_stream_reg* stream_6;

			dma_stream_reg* stream_7;
		}
		port_1,
		port_2;
	}
	dma;

	/// crc calculation unit register
	crc_reg* crc = (crc_reg*) register_map::crc;

	/// debug mcu
	debug_mcu_reg* debug_mcu = (debug_mcu_reg*) 0x00000000;

	/// external interrupt / event (exti)
	exti_reg exti = (exti_reg*) register_map::exti;

	/// power control
	pwr_reg* pwr = (pwr_reg*) register_map::pwr;

	/// real-time clock register
	rtc_reg* rtc = (rtc_reg*) register_map::rtc;

	/// analog to digital converter (adc)
	struct hardware_adc_reg
	{
		/// common
		adc_common_reg* common = (adc_common_reg*) register_map::adc_common;

		/// port 1
		adc_reg* port_1 = (adc_reg*) register_map::adc_1;
	} 
	adc;

	/// general purpose input / output (gpio)
	struct hardware_gpio_reg
	{
		/// port A
		gpio_reg* port_a = (gpio_reg*) register_map::gpio_a;

		/// port B
		gpio_reg* port_b = (gpio_reg*) register_map::gpio_b;

		/// port C
		gpio_reg* port_c = (gpio_reg*) register_map::gpio_c;

		/// port D
		gpio_reg* port_d = (gpio_reg*) register_map::gpio_d;

		/// port E
		gpio_reg* port_e = (gpio_reg*) register_map::gpio_e;

		/// port H
		gpio_reg* port_h = (gpio_reg*) register_map::gpio_h;
	}
	gpio;

	/// inter - integrated circuit interface (i2c)
	struct hardware_i2c_reg
	{
		/// port 1
		i2c_reg* port_1 = (i2c_reg*) register_map::i2c_1;

		/// port 2
		i2c_reg* port_2 = (i2c_reg*) register_map::i2c_2;

		/// port 3
		i2c_reg* port_3 = (i2c_reg*) register_map::i2c_3;
	}
	i2c;

	/// serial peripheral interface (spi)
	struct hardware_spi_reg
	{
		/// port 1
		spi_reg* port_1 = (spi_reg*) register_map::spi_1;

		/// port 2
		spi_reg* port_2 = (spi_reg*)register_map::spi_2;

		/// port 3
		spi_reg* port_3 = (spi_reg*)register_map::spi_3;

		/// port 4
		spi_reg* port_4 = (spi_reg*)register_map::spi_4;
	}
	spi;
}
hardware;