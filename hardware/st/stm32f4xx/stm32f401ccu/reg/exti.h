/**
  * @brief external interrupt / event (exti) controller register
  */
typedef struct
{
	__IO uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	__IO uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
	__IO uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	__IO uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	__IO uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	__IO uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_TypeDef;