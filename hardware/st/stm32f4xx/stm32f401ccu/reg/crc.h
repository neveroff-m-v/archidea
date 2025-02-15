typedef struct
{
	__IO uint32_t DR;         /*!< CRC Data register,             Address offset: 0x00 */
	__IO uint8_t  IDR;        /*!< CRC Independent data register, Address offset: 0x04 */
	uint8_t       RESERVED0;  /*!< Reserved, 0x05                                      */
	uint16_t      RESERVED1;  /*!< Reserved, 0x06                                      */
	__IO uint32_t CR;         /*!< CRC Control register,          Address offset: 0x08 */
} CRC_TypeDef;