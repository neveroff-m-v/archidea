/**
  * @brief direct memory access (dma) controller register
  */
struct dma_stream_reg
{
	volatile u32 cr;     /*!< DMA stream x configuration register      */
	volatile u32 ndtr;   /*!< DMA stream x number of data register     */
	volatile u32 par;    /*!< DMA stream x peripheral address register */
	volatile u32 m0_adr;   /*!< DMA stream x memory 0 address register   */
	volatile u32 m1_adr;   /*!< DMA stream x memory 1 address register   */
	volatile u32 fcr;    /*!< DMA stream x FIFO control register       */
};

struct dma_reg
{
	volatile u32 lisr;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
	volatile u32 hisr;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
	volatile u32 lifcr;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	volatile u32 hifcr;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
};