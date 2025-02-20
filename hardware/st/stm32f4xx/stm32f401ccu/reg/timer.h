/**
* \brief timer register
*/
struct timer_reg
{
	volatile u32 CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
	volatile u32 CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
	volatile u32 SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
	volatile u32 DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
	volatile u32 SR;          /*!< TIM status register,                 Address offset: 0x10 */
	volatile u32 EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
	volatile u32 CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
	volatile u32 CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
	volatile u32 CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
	volatile u32 CNT;         /*!< TIM counter register,                Address offset: 0x24 */
	volatile u32 PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
	volatile u32 ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
	volatile u32 RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
	volatile u32 CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
	volatile u32 CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
	volatile u32 CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
	volatile u32 CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
	volatile u32 BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
	volatile u32 DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
	volatile u32 DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
	volatile u32 OR;          /*!< TIM option register,                 Address offset: 0x50 */
};