/**
* \brief analog to digital converter (adc) register
*/
struct adc_reg
{
	/// status register
	volatile u32 sr;

	/// control register 1
	volatile u32 cr1;

	/// control register 2
	volatile u32 cr2;

	/// sample time register 1
	volatile u32 smpr1;

	/// sample time register 2
	volatile u32 smpr2;

	/// injected channel data offset register 1
	volatile u32 jofr1;

	/// injected channel data offset register 2
	volatile u32 jofr2;

	/// injected channel data offset register 3
	volatile u32 jofr3;

	/// injected channel data offset register 4
	volatile u32 jofr4;

	/// watchdog higher threshold register
	volatile u32 htr;

	/// watchdog lower threshold register
	volatile u32 ltr;

	/// regular sequence register 1
	volatile u32 sqr1;

	/// regular sequence register 2
	volatile u32 sqr2;

	/// regular sequence register 3
	volatile u32 sqr3;

	/// injected sequence register
	volatile u32 jsqr;

	/// injected data register 1
	volatile u32 jdr1;

	/// injected data register 2
	volatile u32 jdr2;

	/// injected data register 3
	volatile u32 jdr3;

	/// injected data register 4
	volatile u32 jdr4;

	/// regular data register
	volatile u32 dr;
};

/**
* \brief common analog to digital converter (adc) register
*/
struct adc_common_reg
{
	/// common status register
	volatile u32 csr;

	/// common control register
	volatile u32 ccr;

	/// regular data register for dual AND triple modes
	volatile u32 cdr;
};