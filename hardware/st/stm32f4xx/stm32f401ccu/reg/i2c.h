/**
* \brief inter-integrated circuit interface (i2c) register
*/
struct i2c_reg
{
	/// control register 1
	volatile u32 cr1;

	/// control register 2
	volatile u32 cr2;

	/// own address register 1
	volatile u32 oar1;

	/// own address register 2
	volatile u32 oar2;

	/// data register
	volatile u32 dr;

	/// status register 1
	volatile u32 sr1;

	/// status register 2
	volatile u32 sr2;

	/// clock control register
	volatile u32 ccr;

	/// trise register
	volatile u32 trise;

	/// fltr register
	volatile u32 fltr;
};