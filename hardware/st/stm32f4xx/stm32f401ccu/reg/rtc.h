/**
* \brief real-time clock register
*/
struct rtc_reg
{
	/// time register
	volatile u32 tr;

	/// date register
	volatile u32 dr;

	/// control register
	volatile u32 cr;

	/// initialization & status register
	volatile u32 isr;

	/// prescaler register
	volatile u32 prer;

	/// wakeup timer register
	volatile u32 wutr;

	/// calibration register
	volatile u32 calibr;

	/// alarm A register
	volatile u32 alrmar;

	/// alarm B register
	volatile u32 alrmbr;

	/// write protection register
	volatile u32 wpr;

	/// sub second register
	volatile u32 ssr;

	/// shift control register
	volatile u32 shiftr;

	/// time stamp time register
	volatile u32 tstr;

	/// time stamp date register
	volatile u32 tsdr;

	/// time-stamp sub second register
	volatile u32 tsssr;

	/// calibration register
	volatile u32 calr;

	/// tamper and alternate function configuration register
	volatile u32 tafcr;

	/// alarm A sub second register
	volatile u32 alrmassr;

	/// alarm B sub second register
	volatile u32 alrmbssr;

	/// reserved (don't use)
	u32		 reserved_0[1];

	/// backup register
	volatile u32 bkpr[20];
};