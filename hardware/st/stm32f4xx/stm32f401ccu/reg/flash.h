/**
* \brief flash register
*/
struct flash_reg
{
	/// access control register
	volatile u32 acr;

	/// key register
	volatile u32 keyr;

	/// option key register
	volatile u32 optkeyr;

	/// status register
	volatile u32 sr;

	/// control register
	volatile u32 cr;

	/// option control register
	volatile u32 optcr;

	/// option control register 1
	volatile u32 optcr1;
};