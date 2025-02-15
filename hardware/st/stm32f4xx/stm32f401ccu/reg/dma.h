/**
  * @brief DMA Controller
  */
struct dma_stream_reg
{
	volatile u32 cr;     /*!< DMA stream x configuration register      */
	volatile u32 NDTR;   /*!< DMA stream x number of data register     */
	volatile u32 PAR;    /*!< DMA stream x peripheral address register */
	volatile u32 M0AR;   /*!< DMA stream x memory 0 address register   */
	volatile u32 M1AR;   /*!< DMA stream x memory 1 address register   */
	volatile u32 FCR;    /*!< DMA stream x FIFO control register       */
};

struct dma_reg
{
	volatile u32 LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
	volatile u32 HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
	volatile u32 LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	volatile u32 HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
};