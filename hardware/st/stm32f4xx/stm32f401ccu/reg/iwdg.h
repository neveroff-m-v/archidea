/**
  * @brief Independent WATCHDOG
  */

typedef struct
{
	__IO uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
	__IO uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
	__IO uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
	__IO uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
} IWDG_TypeDef;