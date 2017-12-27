/*
 * name:        DS1307
 * description: Lowpower serial real-time clock (RTC) with full binary-coded decimal (BCD) clock/calendar plus 56 bytes of NV SRAM.
 * manuf:       Maxim Integrated
 * version:     0.1
 * url:         https://datasheets.maximintegrated.com/en/ds/DS1307.pdf
 * date:        2017-01-11
 * author       https://chisl.io/
 * file:        DS1307.hpp
 */

#include <cinttypes>

/* Derive from class DS1307_Base and implement the read and write functions! */

/* DS1307: Lowpower serial real-time clock (RTC) with full binary-coded decimal (BCD) clock/calendar plus 56 bytes of NV SRAM. */
class DS1307_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG SECS                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG SECS:
	 */
	struct SECS
	{
		static const uint16_t __address = 0;
		
		/* Bits CH: */
		struct CH
		{
			static const uint8_t mask = 0b10000000; // [7]
		};
	};
	
	/* Set register SECS */
	void setSECS(uint8_t value)
	{
		write(SECS::__address, value, 8);
	}
	
	/* Get register SECS */
	uint8_t getSECS()
	{
		return read8(SECS::__address, 8);
	}
	
};
