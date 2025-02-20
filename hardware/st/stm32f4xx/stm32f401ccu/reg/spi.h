/**
* \brief serial peripheral interface (spi) register
*/
struct spi_reg
{
	/// control register 1 (not used in i2s mode)
	volatile u32 cr1;

	/// control register 2
	volatile u32 cr2;

	/// status register
	volatile u32 sr;

	/// data register
	volatile u32 dr;

	/// crc polynomial register (not used in i2s mode)
	volatile u32 crcpr;

	/// rx crc register (not used in i2s mode)
	volatile u32 rx_crcr;

	/// tx crc register (not used in i2s mode)
	volatile u32 tx_crcr;

	/// i2s configuration register
	volatile u32 i2s_cfgr;

	/// i2s prescaler register
	volatile u32 i2s_pr;
};