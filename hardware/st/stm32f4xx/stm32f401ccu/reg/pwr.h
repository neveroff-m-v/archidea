/**
* \brief power control register
*/
struct pwr_reg
{
	/// power control register
	volatile u32 cr;

	/// power control/status register
	volatile u32 csr;
};