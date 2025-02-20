/**
* \brief independent watchdog register
*/
struct iwdt_reg
{
	/// key register
	volatile u32 kr;

	/// prescaler register
	volatile u32 pr;

	/// reload register
	volatile u32 rlr;

	/// status register
	volatile u32 sr;
};