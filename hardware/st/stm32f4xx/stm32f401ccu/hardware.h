/**
* \brief hardware register
*/
struct hardware_reg
{
	/// reset and clock control (rcc)
	rcc_reg* rcc = (rcc_reg*) register_map::rcc;

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
}
hardware;