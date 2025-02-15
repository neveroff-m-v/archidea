
/**
  * @brief Power Control
  */

typedef struct
{
	__IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
	__IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;