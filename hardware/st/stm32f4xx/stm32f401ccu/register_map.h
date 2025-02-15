namespace register_map
{
	enum
	{
		flush =			0x08000000,
		sram =			0x20000000,
		periph =		0x40000000,
		apb1 =			0x40000000 + 0x00000000,
		timer_2 =		0x40000000 + 0x00000000 + 0x0000,
		timer_3 =		0x40000000 + 0x00000000 + 0x0400,
		timer_4 =		0x40000000 + 0x00000000 + 0x0800,
		timer_5 =		0x40000000 + 0x00000000 + 0x0c00,
		rtc =			0x40000000 + 0x00000000 + 0x2800,
		wwdg =			0x40000000 + 0x00000000 + 0x2c00,
		iwdg =			0x40000000 + 0x00000000 + 0x3000,
		i2s_2 =			0x40000000 + 0x00000000 + 0x3400,
		spi_2 =			0x40000000 + 0x00000000 + 0x3800,
		spi_3 =			0x40000000 + 0x00000000 + 0x3c00,
		i2s_3 =			0x40000000 + 0x00000000 + 0x4000,
		uart_2 =		0x40000000 + 0x00000000 + 0x4400,
		i2c_1 =			0x40000000 + 0x00000000 + 0x5400,
		i2c_2 =			0x40000000 + 0x00000000 + 0x5800,
		i2c_3 =			0x40000000 + 0x00000000 + 0x5c00,
		pwr =			0x40000000 + 0x00000000 + 0x7000,
		apb2 =			0x40000000 + 0x00010000,
		timer_1 =		0x40000000 + 0x00010000 + 0x0000,
		usart_1 =		0x40000000 + 0x00010000 + 0x1000,
		usart_6 =		0x40000000 + 0x00010000 + 0x1000,
		adc_1 =			0x40000000 + 0x00010000 + 0x2000,
		adc_common =	0x40000000 + 0x00010000 + 0x2c00,
		sdio =			0x40000000 + 0x00010000 + 0x2c00,
		spi_1 =			0x40000000 + 0x00010000 + 0x3000,
		spi_4 =			0x40000000 + 0x00010000 + 0x3400,
		syscfg =		0x40000000 + 0x00010000 + 0x3800,
		exti =			0x40000000 + 0x00010000 + 0x3c00,
		timer_9 =		0x40000000 + 0x00010000 + 0x4000,
		timer_10 =		0x40000000 + 0x00010000 + 0x4400,
		timer_11 =		0x40000000 + 0x00010000 + 0x4800,
		ahb1 =			0x40000000 + 0x00020000,
		gpio_a =		0x40000000 + 0x00020000 + 0x0000,
		gpio_b =		0x40000000 + 0x00020000 + 0x0400,
		gpio_c =		0x40000000 + 0x00020000 + 0x0800,
		gpio_d =		0x40000000 + 0x00020000 + 0x0c00,
		gpio_e =		0x40000000 + 0x00020000 + 0x1000,
		gpio_h =		0x40000000 + 0x00020000 + 0x1c00,
		crc =			0x40000000 + 0x00020000 + 0x3000,
		rcc =			0x40000000 + 0x00020000 + 0x3800,
		flash_r =		0x40000000 + 0x00020000 + 0x3c00,
		dma_1 =			0x40000000 + 0x00020000 + 0x6000,
		dma_2 =			0x40000000 + 0x00020000 + 0x6400,
		ahb2 =			0x40000000 + 0x10000000,
	};
}

#ifdef X
/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00UL)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000UL)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010UL)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028UL)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040UL)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058UL)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070UL)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088UL)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0UL)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8UL)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400UL)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010UL)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028UL)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040UL)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058UL)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070UL)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088UL)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0UL)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8UL)


/*!< Debug MCU registers base address */
#define DBGMCU_BASE           0xE0042000UL
/*!< USB registers base address */
#define USB_OTG_FS_PERIPH_BASE               0x50000000UL

#define USB_OTG_GLOBAL_BASE                  0x000UL
#define USB_OTG_DEVICE_BASE                  0x800UL
#define USB_OTG_IN_ENDPOINT_BASE             0x900UL
#define USB_OTG_OUT_ENDPOINT_BASE            0xB00UL
#define USB_OTG_EP_REG_SIZE                  0x20UL
#define USB_OTG_HOST_BASE                    0x400UL
#define USB_OTG_HOST_PORT_BASE               0x440UL
#define USB_OTG_HOST_CHANNEL_BASE            0x500UL
#define USB_OTG_HOST_CHANNEL_SIZE            0x20UL
#define USB_OTG_PCGCCTL_BASE                 0xE00UL
#define USB_OTG_FIFO_BASE                    0x1000UL
#define USB_OTG_FIFO_SIZE                    0x1000UL

#define UID_BASE                     0x1FFF7A10UL           /*!< Unique device ID register base address */
#define FLASHSIZE_BASE               0x1FFF7A22UL           /*!< FLASH Size register base address       */
#define PACKAGE_BASE                 0x1FFF7BF0UL           /*!< Package size register base address     */
#endif
