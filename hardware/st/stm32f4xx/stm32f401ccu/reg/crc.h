/**
* \brief crc calculation unit register
*/
struct crc_reg
{
	/// data register
	volatile u32 dr;

	/// independent data register
	volatile u32 idr;

	/// control register
	volatile u32 cr;
};