/**
  * @brief reset and clock control register
  */
struct rcc_reg
{
	/// control register
	volatile u32 cr;

	/// pll configuration register
	volatile u32 pll_cfgr;

	/// configuration register
	volatile u32 cfgr;

	/// clock interrupt register
	volatile u32 cir;

	/// ahb1 peripheral reset register
	volatile u32 ahb1_rstr;

	/// ahb2 peripheral reset register
	volatile u32 ahb2_rstr;

	/// ahb3 peripheral reset register
	volatile u32 ahb3_rstr;

	/// reserved (don't use)
	u32      reserved_0[1];

	/// apb1 peripheral reset register
	volatile u32 apb1_rstr;

	/// apb2 peripheral reset register
	volatile u32 apb2_rstr;

	/// reserved (don't use)
	u32      reserved_1[2];

	/// ahb1 peripheral clock enable register
	volatile u32 ahb1_enr;

	/// ahb2 peripheral clock enable register
	volatile u32 ahb2_enr;

	/// ahb3 peripheral clock enable register
	volatile u32 ahb3_enr;

	/// reserved (don't use)
	u32      reserved_2[1];

	/// apb1 peripheral clock enable register
	volatile u32 apb1_enr;

	/// apb2 peripheral clock enable register
	volatile u32 apb2_enr;

	/// reserved (don't use)
	u32      reserved_3[2];

	/// ahb1 peripheral clock enable in low power mode register
	volatile u32 ahb1_lpenr;

	/// ahb2 peripheral clock enable in low power mode register
	volatile u32 ahb2_lpenr;

	/// ahb3 peripheral clock enable in low power mode register
	volatile u32 ahb3_lpenr;

	/// reserved (don't use)
	u32      reserved_4[1];

	/// apb1 peripheral clock enable in low power mode register
	volatile u32 apb1_lpenr;

	/// apb2 peripheral clock enable in low power mode register
	volatile u32 apb2_lpenr;

	/// reserved (don't use)
	u32      reserved_5[2];

	/// backup domain control register
	volatile u32 bdcr;
	
	/// clock control and status register
	volatile u32 csr;
	
	/// reserved (don't use)
	u32      reserved_6[2];
	
	/// spread spectrum clock generation register
	volatile u32 sscgr;
	
	/// pll i2s configuration register
	volatile u32 pll_i2s_cfgr;
	
	/// reserved (don't use)
	u32      reserver_7[1];

	/// dedicated clocks configuration register
	volatile u32 dck_cfgr;
};