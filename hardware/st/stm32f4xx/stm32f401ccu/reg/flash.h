/**
  * @brief flash registers
  */
struct flash_reg
{
	volatile u32 acr;      /*!< FLASH access control register,   Address offset: 0x00 */
	volatile u32 keyr;     /*!< FLASH key register,              Address offset: 0x04 */
	volatile u32 optkeyr;  /*!< FLASH option key register,       Address offset: 0x08 */
	volatile u32 sr;       /*!< FLASH status register,           Address offset: 0x0C */
	volatile u32 cr;       /*!< FLASH control register,          Address offset: 0x10 */
	volatile u32 optcr;    /*!< FLASH option control register ,  Address offset: 0x14 */
	volatile u32 optcr1;   /*!< FLASH option control register 1, Address offset: 0x18 */
};