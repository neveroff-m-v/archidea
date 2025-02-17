namespace gpio_mode
{
	enum
	{
		/// gpio mode input
		input = 0x0,

		/// gpio mode output
		output = 0x1,

		/// gpio mode alternative function (see reference manual)
		alternative_function = 0x2,

		/// gpio mode analog (adc)
		analog = 0x3
	};
}

namespace gpio_output_type
{
	enum
	{
		/// gpio output type push pull
		push_pull = 0x0,

		/// gpio output type open drain
		open_drain = 0x1
	};
}

namespace gpio_output_speed
{
	enum
	{
		/// gpio speed low
		low = 0x0,

		/// gpio speed medium
		medium = 0x1,

		/// gpio speed high
		high = 0x2,

		/// gpio speed very high
		very_high = 0x3
	};
}

namespace gpio_pull
{
	enum
	{
		/// gpio pull none
		none = 0x0,

		/// gpio pull-up
		pullup = 0x1,

		/// gpio pull-down
		pulldown = 0x2
	};
}

namespace gpio_lock
{
	enum
	{
		/// gpio unlock configuration
		unlock = 0x0,

		/// gpio lock configuration
		lock = 0x1
	};
}

namespace gpio_alternative_function
{
	enum
	{
		/// system
		func_0 = 0,

		/// timer 1...2
		func_1 = 1,

		/// timer 3...5
		func_2 = 2,

		/// timer 9...11
		func_3 = 3,

		/// i2c 1...3
		func_4 = 4,

		/// spi 1...4
		func_5 = 5,

		/// spi 3
		func_6 = 6,

		/// usart 1...2
		func_7 = 7,

		/// usart 6
		func_8 = 8,

		/// i2c 2...3
		func_9 = 9,

		/// otg_fs
		func_10 = 10,

		/// none
		func_11 = 11,

		/// sdio
		func_12 = 12,

		/// none
		func_13 = 13,

		/// none
		func_14 = 14,

		/// eventout
		func_15 = 15,
	};
}

namespace gpio_pin
{
	enum
	{
		pin_0 = 0x00000001,
		pin_1 = 0x00000002,
		pin_2 = 0x00000004,
		pin_3 = 0x00000008,
		pin_4 = 0x00000010,
		pin_5 = 0x00000020,
		pin_6 = 0x00000040,
		pin_7 = 0x00000080,
		pin_8 = 0x00000100,
		pin_9 = 0x00000200,
		pin_10 = 0x00000400,
		pin_11 = 0x00000800,
		pin_12 = 0x00001000,
		pin_13 = 0x00002000,
		pin_14 = 0x00004000,
		pin_15 = 0x00008000,
	};
}

struct gpio_config
{
	struct gpio_config_pin
	{
		u8 mode : 2;
		u8 output_type : 1;
		u8 output_speed : 2;
		u8 pull : 2;
		u8 lock : 1;
		u8 alternative_function : 4;
	}
	pin[16];
};

class gpio_driver
{
public:
	static void get_config(gpio_reg* reg, gpio_config* conf);
	static void set_config(gpio_reg* reg, gpio_config* conf);

	static inline void get_data(gpio_reg* reg, u32* data);
	static inline void set_data(gpio_reg* reg, u32* data);

	static inline u32 get(gpio_reg* reg, u32 mask);
	static inline void set_0(gpio_reg* reg, u32 mask);
	static inline void set_1(gpio_reg* reg, u32 mask);
	static inline void set_r(gpio_reg* reg, u32 mask);
};

void gpio_driver::get_config(gpio_reg* reg, gpio_config* conf)
{
	u32 mode = reg->moder;
	u32 output_type = reg->otyper;
	u32 output_speed = reg->ospeedr;
	u32 pull = reg->pupdr;
	u32 lock = reg->lckr;
	u32 alternative_function_low = reg->afrl;
	u32 alternative_function_high = reg->afrh;

	for (i8 i = 0; i < 16; i++)
	{
		conf->pin[i].mode = mode;
		mode >>= 2;

		conf->pin[i].output_type = output_type;
		output_type >>= 1;

		conf->pin[i].output_speed = output_speed;
		output_speed >>= 2;

		conf->pin[i].pull = pull;
		pull >>= 2;

		conf->pin[i].lock = lock;
		lock >>= 1;
	}

	for (i8 i = 0; i < 8; i++)
	{
		conf->pin[i].alternative_function = alternative_function_low;
		alternative_function_low >>= 4;

		conf->pin[i + 8].alternative_function = alternative_function_high;
		alternative_function_high >>= 4;
	}
}

void gpio_driver::set_config(gpio_reg* reg, gpio_config* conf)
{
	u32 mode = 0x0;
	u32 output_type = 0x0;
	u32 output_speed = 0x0;
	u32 pull = 0x0;
	u32 lock = 0x0;
	u32 alternative_function_low = 0x0;
	u32 alternative_function_high = 0x0;

	for (i8 i = 15; i >= 0; i--)
	{
		mode <<= 2;
		mode |= conf->pin[i].mode;

		output_type <<= 1;
		output_type |= conf->pin[i].output_type;
		
		output_speed <<= 2;
		output_speed |= conf->pin[i].output_speed;
		
		pull <<= 2;
		pull |= conf->pin[i].pull;

		lock <<= 1;
		lock |= conf->pin[i].lock;
	}

	for (i8 i = 7; i >= 0; i--)
	{
		alternative_function_low <<= 4;
		alternative_function_low = conf->pin[i].alternative_function;

		alternative_function_high <<= 4;
		alternative_function_high = conf->pin[i + 8].alternative_function;
	}

	reg->moder = mode;
	reg->otyper = output_type;
	reg->ospeedr = output_speed;
	reg->pupdr = pull;
	reg->lckr = lock;
	reg->afrl = alternative_function_low;
	reg->afrh = alternative_function_high;
}

void gpio_driver::get_data(gpio_reg* reg, u32* data)
{
	(*data) = reg->idr;
}

void gpio_driver::set_data(gpio_reg* reg, u32* data)
{
	reg->odr = (*data);
}

u32 gpio_driver::get(gpio_reg* reg, u32 mask)
{
	return (reg->idr) & mask;
}

void gpio_driver::set_0(gpio_reg* reg, u32 mask)
{
	reg->odr &= ~mask;
}

void gpio_driver::set_1(gpio_reg* reg, u32 mask)
{
	reg->odr |= mask;
}

void gpio_driver::set_r(gpio_reg* reg, u32 mask)
{
	reg->odr ^= mask;
}