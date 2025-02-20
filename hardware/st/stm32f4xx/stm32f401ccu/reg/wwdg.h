/**
* @brief window watchdog register
*/
struct wwdg_reg
{
	/// control register
	volatile u32 CR;

	/// configuration register
	volatile u32 CFR;

	/// status register
	volatile u32 SR;
};