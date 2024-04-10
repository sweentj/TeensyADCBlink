
#ifndef __ADS1015_REG_H
#define __ADS1015_REG_H

#define CONFIG_MUX_OS_SINGLE (1 << 15)

//input mux configuration bit of config reg
#define CONFIG_MUX_AIN0_AIN1 (0 << 12)
#define CONFIG_MUX_AIN0_AIN3 (1 << 12)
#define CONFIG_MUX_AIN1_AIN3 (2 << 12)
#define CONFIG_MUX_AIN2_AIN3 (3 << 12)
#define CONFIG_MUX_SINGLE_AIN0 (4 << 12)
#define CONFIG_MUX_SINGLE_AIN1 (5 << 12)
#define CONFIG_MUX_SINGLE_AIN2 (6 << 12)
#define CONFIG_MUX_SINGLE_AIN3 (7 << 12)

// programmable gain amplifier bits of config reg
#define CONFIG_PGA_6P144V (0 << 9)
#define CONFIG_PGA_4P096V (1 << 9)
#define CONFIG_PGA_2P048V (2 << 9)
#define CONFIG_PGA_1P024V (3 << 9)
#define CONFIG_PGA_0P512V (4 << 9)
#define CONFIG_PGA_0P256V (5 << 9)

#define CONFIG_MODE_CONTNOUS (0 << 8)
#define CONFIG_MODE_SINGLESHOT (1 << 8)

#define CONFIG_DR_128SPS (0 << 5)
#define CONFIG_DR_250SPS (1 << 5)
#define CONFIG_DR_490SPS (2 << 5)
#define CONFIG_DR_920SPS (3 << 5)
#define CONFIG_DR_1600SPS (4 << 5)
#define CONFIG_DR_2400SPS (5 << 5)
#define CONFIG_DR_3300SPS (6 << 5)

#define CONFIG_CMODE_TRAD (0 << 4)
#define CONFIG_CMODE_WNDW (1 << 4)

#define CONFIG_CPOL_LO (0 << 3)
#define CONFIG_CPOL_HI (1 << 3)

#define CONFIG_CLAT_NONLATCH (0 << 2)
#define CONFIG_CLAT_LATCH (1 << 2)

#define CONFIG_CQUE_1CONV (0)
#define CONFIG_CQUE_2CONV (1)
#define CONFIG_CQUE_4CONV (2)
#define CONFIG_CQUE_DISABLE (3)

#endif