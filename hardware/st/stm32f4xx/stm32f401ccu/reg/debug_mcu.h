typedef struct
{
	__IO uint32_t IDCODE;  /*!< MCU device ID code,               Address offset: 0x00 */
	__IO uint32_t CR;      /*!< Debug MCU configuration register, Address offset: 0x04 */
	__IO uint32_t APB1FZ;  /*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
	__IO uint32_t APB2FZ;  /*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */
} DBGMCU_TypeDef;