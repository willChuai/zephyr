/*
 * Copyright (c) 2022 hpmicro
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <init.h>
extern void board_init_ahb(void);

__attribute__((weak)) void _init_noncache(void)
{
	uint32_t i, size;

	extern uint8_t __noncacheable_data_load_start[];
	extern uint8_t __noncacheable_bss_start__[], __noncacheable_bss_end__[];
	extern uint8_t __noncacheable_init_start__[], __noncacheable_init_end__[];

	/* noncacheable bss section */
	size = __noncacheable_bss_end__ - __noncacheable_bss_start__;
	for (i = 0; i < size; i++) {
		*(__noncacheable_bss_start__ + i) = 0;
	}

	/* noncacheable init section LMA: etext + data length + ramfunc legnth */
	size = __noncacheable_init_end__ - __noncacheable_init_start__;
	for (i = 0; i < size; i++) {
		*(__noncacheable_init_start__ + i) = *(__noncacheable_data_load_start + i);
	}
}

static int hpmicro_soc_init(const struct device *dev)
{
	uint32_t key;

	ARG_UNUSED(dev);

	key = irq_lock();

	board_init_clock();
	board_init_pmp();
	board_init_ahb();

	irq_unlock(key);

	return 0;
}

SYS_INIT(hpmicro_soc_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
