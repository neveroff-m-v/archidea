/**
* \brief system configuration controller (sysconfig)
*/
typedef struct
{
	volatile u32 MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
	volatile u32 PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
	volatile u32 EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
	uint32_t      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
	volatile u32 CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
} SYSCFG_TypeDef;