
/**
  * @brief Serial Peripheral Interface
  */

typedef struct
{
	__IO uint32_t CR1;        /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	__IO uint32_t CR2;        /*!< SPI control register 2,                             Address offset: 0x04 */
	__IO uint32_t SR;         /*!< SPI status register,                                Address offset: 0x08 */
	__IO uint32_t DR;         /*!< SPI data register,                                  Address offset: 0x0C */
	__IO uint32_t CRCPR;      /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	__IO uint32_t RXCRCR;     /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	__IO uint32_t TXCRCR;     /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	__IO uint32_t I2SCFGR;    /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
	__IO uint32_t I2SPR;      /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;