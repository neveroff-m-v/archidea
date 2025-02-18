struct debug_mcu_reg
{
	/// mcu device id code
	volatile u32 mcu_id;

	/// debug mcu configuration register
	volatile u32 cr;

	/// debug mcu apb1 freeze register
	volatile u32 apb1_fz;

	/// debug mcu apb2 freeze register
	volatile u32 apb2_fz;
};