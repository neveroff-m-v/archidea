/**
* \brief direct memory access (dma) stream register
*/
struct dma_stream_reg
{
	/// configuration register
	volatile u32 cr;

	/// number of data register
	volatile u32 ndtr;

	/// peripheral address register
	volatile u32 par;

	/// memory 0 address register
	volatile u32 m0_adr;

	/// memory 1 address register
	volatile u32 m1_adr;

	/// fifo control register
	volatile u32 fcr;
};

/**
* \brief direct memory access (dma) register
*/
struct dma_reg
{
	/// low interrupt status register
	volatile u32 lisr;

	/// high interrupt status register
	volatile u32 hisr;

	/// low interrupt flag clear register
	volatile u32 lifcr;

	/// high interrupt flag clear register
	volatile u32 hifcr;
};