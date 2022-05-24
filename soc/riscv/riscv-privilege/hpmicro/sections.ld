/*
 * Copyright (c) 2022 hpmicro
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */
#include <linker/linker-tool.h>
#include <devicetree.h>

SECTIONS
{
	SECTION_PROLOGUE(.entry,,)
	{
		. = ALIGN(4);
		KEEP(*(.init.*))
	} GROUP_LINK_IN(CORE0_LM_SLV)

	SECTION_PROLOGUE(.noncacheable,,)
	{
		. = ALIGN(8);
		__noncacheable_init_start__ = .;
		KEEP(*(.noncacheable.init))
		__noncacheable_init_end__ = .;
		KEEP(*(.noncacheable))
		__noncacheable_bss_start__ = .;
		KEEP(*(.noncacheable.bss))
		__noncacheable_bss_end__ = .;
		. = ALIGN(8);
	} GROUP_LINK_IN(NONCACHEABLE AT> ROMABLE_REGION)
	__noncacheable_data_load_start = LOADADDR(.noncacheable);
	__noncacheable_start__ = ORIGIN(NONCACHEABLE);
	__noncacheable_end__ = ORIGIN(NONCACHEABLE) + LENGTH(NONCACHEABLE);
}
