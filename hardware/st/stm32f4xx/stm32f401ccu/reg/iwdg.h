/**
  * @brief independent watchdog
  */
struct iwdt_reg
{
	volatile u32 kr;   /*!< IWDG Key register,       Address offset: 0x00 */
	volatile u32 pr;   /*!< IWDG Prescaler register, Address offset: 0x04 */
	volatile u32 rlr;  /*!< IWDG Reload register,    Address offset: 0x08 */
	volatile u32 sr;   /*!< IWDG Status register,    Address offset: 0x0C */
};