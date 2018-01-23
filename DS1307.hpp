/*
 * name:        DS1307
 * description: Lowpower serial real-time clock (RTC) with full binary-coded decimal (BCD) clock/calendar plus 56 bytes of NV SRAM.
 * manuf:       Maxim Integrated
 * version:     Version 0.1
 * url:         https://datasheets.maximintegrated.com/en/ds/DS1307.pdf
 * date:        2017-01-11
 * author       https://chisl.io/
 * file:        DS1307.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class DS1307_Base and implement the read and write functions! */

/* DS1307: Lowpower serial real-time clock (RTC) with full binary-coded decimal (BCD) clock/calendar plus 56 bytes of NV SRAM. */
class DS1307_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG SECONDS                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SECONDS:
	 * Seconds 00–59
	 */
	struct SECONDS
	{
		static const uint16_t __address = 0;
		
		/* Bits CH: */
		/*
		 * The clock halt bit. When this bit is set to '1', the oscillator is disabled.
		 * When cleared to '0', the oscillator is enabled.
		 * The clock can be halted whenever the timekeeping functions are not required,
		 * which minimizes current (IBATDR).
		 */
		struct CH
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t OSC_ENABLE = 0b0; // 
			static const uint8_t OSC_DISABLE = 0b1; // 
		};
		/* Bits SECS_10: */
		struct SECS_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b01110000; // [4,5,6]
		};
		/* Bits SECS: */
		struct SECS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register SECONDS */
	void setSECONDS(uint8_t value)
	{
		write(SECONDS::__address, value, 8);
	}
	
	/* Get register SECONDS */
	uint8_t getSECONDS()
	{
		return read8(SECONDS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG MINUTES                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG MINUTES:
	 * Minutes 00–59
	 */
	struct MINUTES
	{
		static const uint16_t __address = 1;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits MINUTES_10: */
		struct MINUTES_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b01110000; // [4,5,6]
		};
		/* Bits MINUTES: */
		struct MINUTES_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register MINUTES */
	void setMINUTES(uint8_t value)
	{
		write(MINUTES::__address, value, 8);
	}
	
	/* Get register MINUTES */
	uint8_t getMINUTES()
	{
		return read8(MINUTES::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                     REG HOURS, variant AM_PM                                      *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG HOURS_AM_PM:
	 * Hours 1–12
	 * The DS1307 can be run in either 12-hour or 24-hour mode. Bit 6 of the hours register is defined as the 12-hour or
	 * 24-hour mode-select bit. When high, the 12-hour mode is selected. In the 12-hour mode, bit 5 is the AM/PM bit with
	 * logic high being PM. In the 24-hour mode, bit 5 is the second 10-hour bit (20 to 23 hours). The hours value must be
	 * re-entered whenever the 12/24-hour mode bit is changed.
	 */
	struct HOURS_AM_PM
	{
		static const uint16_t __address = 2;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits H12_24: */
		struct H12_24
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t H24 = 0b0; // 
			static const uint8_t H12 = 0b1; // 
		};
		/* Bits AM_PM: */
		struct AM_PM
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t AM = 0b0; // 
			static const uint8_t PM = 0b1; // 
		};
		/* Bits HOUR_10: */
		struct HOUR_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits HOURS: */
		struct HOURS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register HOURS_AM_PM */
	void setHOURS_AM_PM(uint8_t value)
	{
		write(HOURS_AM_PM::__address, value, 8);
	}
	
	/* Get register HOURS */
	uint8_t getHOURS_AM_PM()
	{
		return read8(HOURS_AM_PM::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                      REG HOURS, variant H24                                       *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG HOURS_H24:
	 * Hours 00-23
	 * The DS1307 can be run in either 12-hour or 24-hour mode. Bit 6 of the hours register is defined as the 12-hour or
	 * 24-hour mode-select bit. When high, the 12-hour mode is selected. In the 12-hour mode, bit 5 is the AM/PM bit with
	 * logic high being PM. In the 24-hour mode, bit 5 is the second 10-hour bit (20 to 23 hours). The hours value must be
	 * re-entered whenever the 12/24-hour mode bit is changed.
	 */
	struct HOURS_H24
	{
		static const uint16_t __address = 2;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits H12_24: */
		struct H12_24
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t H24 = 0b0; // 
			static const uint8_t H12 = 0b1; // 
		};
		/* Bits HOUR_10: */
		struct HOUR_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits HOURS: */
		/* BCD format */
		struct HOURS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register HOURS_H24 */
	void setHOURS_H24(uint8_t value)
	{
		write(HOURS_H24::__address, value, 8);
	}
	
	/* Get register HOURS */
	uint8_t getHOURS_H24()
	{
		return read8(HOURS_H24::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                             REG DAY                                              *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DAY:
	 * Day 01–07
	 */
	struct DAY
	{
		static const uint16_t __address = 3;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000; // 5'd0
			static const uint8_t mask = 0b11111000; // [3,4,5,6,7]
		};
		/* Bits DAY: */
		/* BCD format */
		struct DAY_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	
	/* Set register DAY */
	void setDAY(uint8_t value)
	{
		write(DAY::__address, value, 8);
	}
	
	/* Get register DAY */
	uint8_t getDAY()
	{
		return read8(DAY::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG DATE                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG DATE:
	 * Date 01–31
	 */
	struct DATE
	{
		static const uint16_t __address = 4;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'd0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits DATE_10: */
		struct DATE_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits DATE: */
		/* BCD format */
		struct DATE_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register DATE */
	void setDATE(uint8_t value)
	{
		write(DATE::__address, value, 8);
	}
	
	/* Get register DATE */
	uint8_t getDATE()
	{
		return read8(DATE::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG MONTH                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG MONTH:
	 * Month 01–12
	 */
	struct MONTH
	{
		static const uint16_t __address = 5;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'd0
			static const uint8_t mask = 0b11100000; // [5,6,7]
		};
		/* Bits MONTH_10: */
		struct MONTH_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits MONTH: */
		/* BCD format */
		struct MONTH_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register MONTH */
	void setMONTH(uint8_t value)
	{
		write(MONTH::__address, value, 8);
	}
	
	/* Get register MONTH */
	uint8_t getMONTH()
	{
		return read8(MONTH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG YEAR                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG YEAR:
	 * Year 00–99
	 */
	struct YEAR
	{
		static const uint16_t __address = 6;
		
		/* Bits YEAR_10: */
		/* BCD format */
		struct YEAR_10
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits YEAR: */
		/* BCD format */
		struct YEAR_
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register YEAR */
	void setYEAR(uint8_t value)
	{
		write(YEAR::__address, value, 8);
	}
	
	/* Get register YEAR */
	uint8_t getYEAR()
	{
		return read8(YEAR::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG CONTROL                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CONTROL:
	 * The DS1307 control register is used to control the operation of the SQW/OUT pin.
	 */
	struct CONTROL
	{
		static const uint16_t __address = 7;
		
		/* Bits OUT: */
		/*
		 * Output Control:
		 * This bit controls the output level of the SQW/OUT pin when the square-wave output
		 * is disabled. If SQWE = 0, the logic level on the SQW/OUT pin is 1 if OUT = 1 and is 0 if OUT = 0. On initial
		 * application of power to the device, this bit is typically set to a 0.
		 */
		struct OUT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t LEVEL_0 = 0b0; // 
			static const uint8_t LEVEL_1 = 0b1; // 
		};
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b01100000; // [5,6]
		};
		/* Bits SQWE: */
		/*
		 * Square-Wave Enable:
		 * This bit, when set to logic 1, enables the oscillator output. The frequency of
		 * the square-wave output depends upon the value of the RS0 and RS1 bits. With the square-wave output set to 1Hz,
		 * the clock registers update on the falling edge of the square wave. On initial application of power to the device, this
		 * bit is typically set to a 0.
		 */
		struct SQWE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t DISABLE = 0b0; // 
			static const uint8_t ENABLE = 0b1; // 
		};
		/* Bits unused_1: */
		struct unused_1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00001100; // [2,3]
		};
		/* Bits RS: */
		/*
		 * Rate Select:
		 * These bits control the frequency of the square-wave output when the squarewave
		 * output has been enabled. On initial application of power to the device, these bits are typically set to a 1.
		 * See table: (p.9)
		 * | RS1 | RS0 | SQW/OUT OUTPUT | SQWE | OUT |
		 * |-----|-----|-----------------------|-----|
		 * | 0   | 0   | 1Hz            | 1    | X   |
		 * | 0   | 1   | 4.096kHz       | 1    | X   |
		 * | 1   | 0   | 8.192kHz       | 1    | X   |
		 * | 1   | 1   | 32.768kHz      | 1    | X   |
		 * | X   | X   | 0              | 0    | 0   |
		 * | X   | X   | 1              | 0    | 1   |
		 * 
		 */
		struct RS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b11; // 2'b11
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t F1Hz = 0b00; // 
			static const uint8_t F4_096kHz = 0b01; // 
			static const uint8_t F8_192kHz = 0b10; // 
			static const uint8_t F32_768kHz = 0b11; // 
		};
	};
	
	/* Set register CONTROL */
	void setCONTROL(uint8_t value)
	{
		write(CONTROL::__address, value, 8);
	}
	
	/* Get register CONTROL */
	uint8_t getCONTROL()
	{
		return read8(CONTROL::__address, 8);
	}
	
};
