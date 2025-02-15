struct rcc_config
{
	struct rcc_config_control
	{
		u8 reserved_0 : 4;
		u8 pll_i2s_ready : 1;
		u8 pll_i2s_on : 1;
		u8 pll_ready : 1;
		u8 pll_on : 1;
		u8 reserved_1 : 4;
		u8 css_on : 1;
		u8 hse_bypass : 1;
		u8 hse_ready : 1;
		u8 hse_on : 1;
		u8 hsi_calibration : 8;
		u8 hsi_trimming : 5;
		u8 reserved_2 : 1;
		u8 hsi_ready : 1;
		u8 hsi_on : 1;
	} control;
};

class rcc_driver
{
public:
	static void get_config(rcc_config* conf);
	static void set_config(rcc_config* conf);
};

void rcc_driver::get_config(rcc_config* conf)
{
	//conf->control = hardware.rcc->cr;
}