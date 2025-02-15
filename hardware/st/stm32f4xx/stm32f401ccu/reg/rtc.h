
/**
  * @brief Real-Time Clock
  */

typedef struct
{
	__IO uint32_t TR;      /*!< RTC time register,                                        Address offset: 0x00 */
	__IO uint32_t DR;      /*!< RTC date register,                                        Address offset: 0x04 */
	__IO uint32_t CR;      /*!< RTC control register,                                     Address offset: 0x08 */
	__IO uint32_t ISR;     /*!< RTC initialization and status register,                   Address offset: 0x0C */
	__IO uint32_t PRER;    /*!< RTC prescaler register,                                   Address offset: 0x10 */
	__IO uint32_t WUTR;    /*!< RTC wakeup timer register,                                Address offset: 0x14 */
	__IO uint32_t CALIBR;  /*!< RTC calibration register,                                 Address offset: 0x18 */
	__IO uint32_t ALRMAR;  /*!< RTC alarm A register,                                     Address offset: 0x1C */
	__IO uint32_t ALRMBR;  /*!< RTC alarm B register,                                     Address offset: 0x20 */
	__IO uint32_t WPR;     /*!< RTC write protection register,                            Address offset: 0x24 */
	__IO uint32_t SSR;     /*!< RTC sub second register,                                  Address offset: 0x28 */
	__IO uint32_t SHIFTR;  /*!< RTC shift control register,                               Address offset: 0x2C */
	__IO uint32_t TSTR;    /*!< RTC time stamp time register,                             Address offset: 0x30 */
	__IO uint32_t TSDR;    /*!< RTC time stamp date register,                             Address offset: 0x34 */
	__IO uint32_t TSSSR;   /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
	__IO uint32_t CALR;    /*!< RTC calibration register,                                 Address offset: 0x3C */
	__IO uint32_t TAFCR;   /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
	__IO uint32_t ALRMASSR;/*!< RTC alarm A sub second register,                          Address offset: 0x44 */
	__IO uint32_t ALRMBSSR;/*!< RTC alarm B sub second register,                          Address offset: 0x48 */
	uint32_t RESERVED7;    /*!< Reserved, 0x4C                                                                 */
	__IO uint32_t BKP0R;   /*!< RTC backup register 1,                                    Address offset: 0x50 */
	__IO uint32_t BKP1R;   /*!< RTC backup register 1,                                    Address offset: 0x54 */
	__IO uint32_t BKP2R;   /*!< RTC backup register 2,                                    Address offset: 0x58 */
	__IO uint32_t BKP3R;   /*!< RTC backup register 3,                                    Address offset: 0x5C */
	__IO uint32_t BKP4R;   /*!< RTC backup register 4,                                    Address offset: 0x60 */
	__IO uint32_t BKP5R;   /*!< RTC backup register 5,                                    Address offset: 0x64 */
	__IO uint32_t BKP6R;   /*!< RTC backup register 6,                                    Address offset: 0x68 */
	__IO uint32_t BKP7R;   /*!< RTC backup register 7,                                    Address offset: 0x6C */
	__IO uint32_t BKP8R;   /*!< RTC backup register 8,                                    Address offset: 0x70 */
	__IO uint32_t BKP9R;   /*!< RTC backup register 9,                                    Address offset: 0x74 */
	__IO uint32_t BKP10R;  /*!< RTC backup register 10,                                   Address offset: 0x78 */
	__IO uint32_t BKP11R;  /*!< RTC backup register 11,                                   Address offset: 0x7C */
	__IO uint32_t BKP12R;  /*!< RTC backup register 12,                                   Address offset: 0x80 */
	__IO uint32_t BKP13R;  /*!< RTC backup register 13,                                   Address offset: 0x84 */
	__IO uint32_t BKP14R;  /*!< RTC backup register 14,                                   Address offset: 0x88 */
	__IO uint32_t BKP15R;  /*!< RTC backup register 15,                                   Address offset: 0x8C */
	__IO uint32_t BKP16R;  /*!< RTC backup register 16,                                   Address offset: 0x90 */
	__IO uint32_t BKP17R;  /*!< RTC backup register 17,                                   Address offset: 0x94 */
	__IO uint32_t BKP18R;  /*!< RTC backup register 18,                                   Address offset: 0x98 */
	__IO uint32_t BKP19R;  /*!< RTC backup register 19,                                   Address offset: 0x9C */
} RTC_TypeDef;