/**
  * @brief inter-integrated circuit interface (i2c) register
  */
struct i2c_reg
{
	volatile u32 cr1;        /*!< I2C Control register 1,     Address offset: 0x00 */
	volatile u32 cr2;        /*!< I2C Control register 2,     Address offset: 0x04 */
	volatile u32 oar1;       /*!< I2C Own address register 1, Address offset: 0x08 */
	volatile u32 oar2;       /*!< I2C Own address register 2, Address offset: 0x0C */
	volatile u32 dr;         /*!< I2C Data register,          Address offset: 0x10 */
	volatile u32 sr1;        /*!< I2C Status register 1,      Address offset: 0x14 */
	volatile u32 sr2;        /*!< I2C Status register 2,      Address offset: 0x18 */
	volatile u32 ccr;        /*!< I2C Clock control register, Address offset: 0x1C */
	volatile u32 trise;      /*!< I2C TRISE register,         Address offset: 0x20 */
	volatile u32 fltr;       /*!< I2C FLTR register,          Address offset: 0x24 */
};