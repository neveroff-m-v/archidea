/**
  * @brief USB_OTG_Core_Registers
  */
typedef struct
{
	__IO uint32_t GOTGCTL;              /*!< USB_OTG Control and Status Register          000h */
	__IO uint32_t GOTGINT;              /*!< USB_OTG Interrupt Register                   004h */
	__IO uint32_t GAHBCFG;              /*!< Core AHB Configuration Register              008h */
	__IO uint32_t GUSBCFG;              /*!< Core USB Configuration Register              00Ch */
	__IO uint32_t GRSTCTL;              /*!< Core Reset Register                          010h */
	__IO uint32_t GINTSTS;              /*!< Core Interrupt Register                      014h */
	__IO uint32_t GINTMSK;              /*!< Core Interrupt Mask Register                 018h */
	__IO uint32_t GRXSTSR;              /*!< Receive Sts Q Read Register                  01Ch */
	__IO uint32_t GRXSTSP;              /*!< Receive Sts Q Read & POP Register            020h */
	__IO uint32_t GRXFSIZ;              /*!< Receive FIFO Size Register                   024h */
	__IO uint32_t DIEPTXF0_HNPTXFSIZ;   /*!< EP0 / Non Periodic Tx FIFO Size Register     028h */
	__IO uint32_t HNPTXSTS;             /*!< Non Periodic Tx FIFO/Queue Sts reg           02Ch */
	uint32_t Reserved30[2];             /*!< Reserved                                     030h */
	__IO uint32_t GCCFG;                /*!< General Purpose IO Register                  038h */
	__IO uint32_t CID;                  /*!< User ID Register                             03Ch */
	uint32_t  Reserved40[48];           /*!< Reserved                                0x40-0xFF */
	__IO uint32_t HPTXFSIZ;             /*!< Host Periodic Tx FIFO Size Reg               100h */
	__IO uint32_t DIEPTXF[0x0F];        /*!< dev Periodic Transmit FIFO                        */
} USB_OTG_GlobalTypeDef;

/**
  * @brief USB_OTG_device_Registers
  */
typedef struct
{
	__IO uint32_t DCFG;            /*!< dev Configuration Register   800h */
	__IO uint32_t DCTL;            /*!< dev Control Register         804h */
	__IO uint32_t DSTS;            /*!< dev Status Register (RO)     808h */
	uint32_t Reserved0C;           /*!< Reserved                     80Ch */
	__IO uint32_t DIEPMSK;         /*!< dev IN Endpoint Mask         810h */
	__IO uint32_t DOEPMSK;         /*!< dev OUT Endpoint Mask        814h */
	__IO uint32_t DAINT;           /*!< dev All Endpoints Itr Reg    818h */
	__IO uint32_t DAINTMSK;        /*!< dev All Endpoints Itr Mask   81Ch */
	uint32_t  Reserved20;          /*!< Reserved                     820h */
	uint32_t Reserved9;            /*!< Reserved                     824h */
	__IO uint32_t DVBUSDIS;        /*!< dev VBUS discharge Register  828h */
	__IO uint32_t DVBUSPULSE;      /*!< dev VBUS Pulse Register      82Ch */
	__IO uint32_t DTHRCTL;         /*!< dev threshold                830h */
	__IO uint32_t DIEPEMPMSK;      /*!< dev empty msk                834h */
	__IO uint32_t DEACHINT;        /*!< dedicated EP interrupt       838h */
	__IO uint32_t DEACHMSK;        /*!< dedicated EP msk             83Ch */
	uint32_t Reserved40;           /*!< dedicated EP mask            840h */
	__IO uint32_t DINEP1MSK;       /*!< dedicated EP mask            844h */
	uint32_t  Reserved44[15];      /*!< Reserved                 844-87Ch */
	__IO uint32_t DOUTEP1MSK;      /*!< dedicated EP msk             884h */
} USB_OTG_DeviceTypeDef;

/**
  * @brief USB_OTG_IN_Endpoint-Specific_Register
  */
typedef struct
{
	__IO uint32_t DIEPCTL;           /*!< dev IN Endpoint Control Reg    900h + (ep_num * 20h) + 00h */
	uint32_t Reserved04;             /*!< Reserved                       900h + (ep_num * 20h) + 04h */
	__IO uint32_t DIEPINT;           /*!< dev IN Endpoint Itr Reg        900h + (ep_num * 20h) + 08h */
	uint32_t Reserved0C;             /*!< Reserved                       900h + (ep_num * 20h) + 0Ch */
	__IO uint32_t DIEPTSIZ;          /*!< IN Endpoint Txfer Size         900h + (ep_num * 20h) + 10h */
	__IO uint32_t DIEPDMA;           /*!< IN Endpoint DMA Address Reg    900h + (ep_num * 20h) + 14h */
	__IO uint32_t DTXFSTS;           /*!< IN Endpoint Tx FIFO Status Reg 900h + (ep_num * 20h) + 18h */
	uint32_t Reserved18;             /*!< Reserved  900h+(ep_num*20h)+1Ch-900h+ (ep_num * 20h) + 1Ch */
} USB_OTG_INEndpointTypeDef;

/**
  * @brief USB_OTG_OUT_Endpoint-Specific_Registers
  */
typedef struct
{
	__IO uint32_t DOEPCTL;       /*!< dev OUT Endpoint Control Reg           B00h + (ep_num * 20h) + 00h */
	uint32_t Reserved04;         /*!< Reserved                               B00h + (ep_num * 20h) + 04h */
	__IO uint32_t DOEPINT;       /*!< dev OUT Endpoint Itr Reg               B00h + (ep_num * 20h) + 08h */
	uint32_t Reserved0C;         /*!< Reserved                               B00h + (ep_num * 20h) + 0Ch */
	__IO uint32_t DOEPTSIZ;      /*!< dev OUT Endpoint Txfer Size            B00h + (ep_num * 20h) + 10h */
	__IO uint32_t DOEPDMA;       /*!< dev OUT Endpoint DMA Address           B00h + (ep_num * 20h) + 14h */
	uint32_t Reserved18[2];      /*!< Reserved B00h + (ep_num * 20h) + 18h - B00h + (ep_num * 20h) + 1Ch */
} USB_OTG_OUTEndpointTypeDef;

/**
  * @brief USB_OTG_Host_Mode_Register_Structures
  */
typedef struct
{
	__IO uint32_t HCFG;             /*!< Host Configuration Register          400h */
	__IO uint32_t HFIR;             /*!< Host Frame Interval Register         404h */
	__IO uint32_t HFNUM;            /*!< Host Frame Nbr/Frame Remaining       408h */
	uint32_t Reserved40C;           /*!< Reserved                             40Ch */
	__IO uint32_t HPTXSTS;          /*!< Host Periodic Tx FIFO/ Queue Status  410h */
	__IO uint32_t HAINT;            /*!< Host All Channels Interrupt Register 414h */
	__IO uint32_t HAINTMSK;         /*!< Host All Channels Interrupt Mask     418h */
} USB_OTG_HostTypeDef;

/**
  * @brief USB_OTG_Host_Channel_Specific_Registers
  */
typedef struct
{
	__IO uint32_t HCCHAR;           /*!< Host Channel Characteristics Register    500h */
	__IO uint32_t HCSPLT;           /*!< Host Channel Split Control Register      504h */
	__IO uint32_t HCINT;            /*!< Host Channel Interrupt Register          508h */
	__IO uint32_t HCINTMSK;         /*!< Host Channel Interrupt Mask Register     50Ch */
	__IO uint32_t HCTSIZ;           /*!< Host Channel Transfer Size Register      510h */
	__IO uint32_t HCDMA;            /*!< Host Channel DMA Address Register        514h */
	uint32_t Reserved[2];           /*!< Reserved                                      */
} USB_OTG_HostChannelTypeDef;