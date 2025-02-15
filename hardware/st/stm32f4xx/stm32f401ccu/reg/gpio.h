/**
* \brief general purpose input / output (gpio) register
*/
struct gpio_reg
{
	/// mode register
	volatile u32 moder;

	/// output type register
	volatile u32 otyper;

	/// output speed register
	volatile u32 ospeedr;

	/// pull-up / pull-down register
	volatile u32 pupdr;

	/// input data register
	volatile u32 idr;

	/// output data register
	volatile u32 odr;

	/// bit set / reset register
	volatile u32 bsrr;

	/// configuration lock register
	volatile u32 lckr;

	/// alternate function low register
	volatile u32 afrl;

	/// alternate function high register
	volatile u32 afrh;
};