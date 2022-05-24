/*
 * Copyright (c) 2022 hpmicro
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef __RISCV_HPMICRO_SOC_H_
#define __RISCV_HPMICRO_SOC_H_

#include <soc_common.h>
#include <zephyr/devicetree.h>

/* Machine timer memory-mapped registers */
#define RISCV_MTIME_BASE             DT_REG_ADDR_BY_IDX(DT_NODELABEL(mtimer), 0)
#define RISCV_MTIMECMP_BASE          DT_REG_ADDR_BY_IDX(DT_NODELABEL(mtimer), 1)

/* lib-c hooks required RAM defined variables */
#define RISCV_RAM_BASE               CONFIG_SRAM_BASE_ADDRESS
#define RISCV_RAM_SIZE               KB(CONFIG_SRAM_SIZE)

/* Include CSRs available for Andes V5 SoCs */
#ifndef _ASMLANGUAGE
#include <toolchain.h>
#include <hpm_common.h>
#include <hpm_soc.h>
#include <board.h>
#endif  /* !_ASMLANGUAGE */


#endif /* __RISCV_HPMICRO_SOC_H_ */
