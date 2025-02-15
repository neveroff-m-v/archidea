namespace gpio_mode
{
	enum
	{
		input = 0x0,
		output = 0x1,
		alternative_function = 0x2,
		analog = 0x3
	};
}

namespace gpio_output_type
{
	enum
	{
		push_pull = 0x0,
		open_drain = 0x1
	};
}

namespace gpio_output_speed
{
	enum
	{
		low = 0x0,
		medium = 0x1,
		high = 0x2,
		very_high = 0x3
	};
}

namespace gpio_pull
{
	enum
	{
		none = 0x0,
		pullup = 0x1,
		pulldown = 0x2
	};
}

namespace gpio_lock
{
	enum
	{
		unlock = 0x0,
		lock = 0x1
	};
}

namespace gpio_alternative_function
{
	enum
	{
		system = 0,

		timer_1 = 1,
		timer_2 = 1,

		timer_3 = 2,
		timer_4 = 2,
		timer_5 = 2,

		timer_9 = 3,
		timer_10 = 3,
		timer_11 = 3,

		i2c_1 = 4,
		i2c_2 = 4,
		i2c_3 = 4,
	};
}

namespace gpio_pin
{
	enum
	{
		pin_0 = 0x00000001,
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

	static void set(gpio_reg* reg, u32 data);
	static void set_0(gpio_reg* reg, u32 mask);
	static void set_1(gpio_reg* reg, u32 mask);
	static void set_r(gpio_reg* reg, u32 mask);
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

	for (u8 i = 0; i < 16; i++)
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

	for (u8 i = 0; i < 8; i++)
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

	for (u8 i = 15; i >= 0; i--)
	{
		mode |= conf->pin[i].mode;
		mode <<= 2;

		output_type |= conf->pin[i].output_type;
		output_type <<= 1;

		output_speed |= conf->pin[i].output_speed;
		output_speed <<= 2;

		pull |= conf->pin[i].pull;
		pull <<= 2;

		lock |= conf->pin[i].lock;
		lock <<= 1;
	}

	for (u8 i = 7; i >= 0; i--)
	{
		alternative_function_low = conf->pin[i].alternative_function;
		alternative_function_low <<= 4;

		alternative_function_high = conf->pin[i + 8].alternative_function;
		alternative_function_high <<= 4;
	}

	reg->moder = mode;
	reg->otyper = output_type;
	reg->ospeedr = output_speed;
	reg->pupdr = pull;
	reg->lckr = lock;
	reg->afrl = alternative_function_low;
	reg->afrh = alternative_function_high;
}

void gpio_driver::set(gpio_reg* reg, u32 data)
{
	reg->odr = data;
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