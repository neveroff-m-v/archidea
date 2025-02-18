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
		/// pin 0
		pin_0 = 0x0001,

		/// pin 1
		pin_1 = 0x0002,

		/// pin 2
		pin_2 = 0x0004,

		/// pin 3
		pin_3 = 0x0008,

		/// pin 4
		pin_4 = 0x0010,

		/// pin 5
		pin_5 = 0x0020,

		/// pin 6
		pin_6 = 0x0040,

		/// pin 7
		pin_7 = 0x0080,

		/// pin 8
		pin_8 = 0x0100,

		/// pin 9
		pin_9 = 0x0200,

		/// pin 10
		pin_10 = 0x0400,

		/// pin 11
		pin_11 = 0x0800,

		/// pin 12
		pin_12 = 0x1000,

		/// pin 13
		pin_13 = 0x2000,

		/// pin 14
		pin_14 = 0x4000,

		/// pin 15
		pin_15 = 0x8000,
	};
}

/**
* \brief gpio configuration
*/
struct gpio_config
{
	struct gpio_config_pin
	{
		/// gpio mode
		u8 mode : 2;

		/// gpio output type
		u8 output_type : 1;

		/// gpio output speed
		u8 output_speed : 2;

		/// gpio pull-up / pull-down
		u8 pull : 2;

		/// gpio lock configuration
		u8 lock : 1;

		/// gpio alternative function
		u8 alternative_function : 4;
	}
	/// pins
	pin[16];
};

/**
* \brief general purpose input / output (gpio) driver
*/
class gpio_driver
{
public:
	/**
	* \brief gets gpio configuration [conf] from definite register [reg]
	* \param [reg] gpio register
	* \param [conf] gpio configuration
	* \returns none
	*/
	static void get_config(gpio_reg* reg, gpio_config* conf);

	/**
	* \brief sets gpio configuration [conf] into definite register [reg]
	* \param [reg] gpio register
	* \param [conf] gpio configuration
	* \returns none
	*/
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