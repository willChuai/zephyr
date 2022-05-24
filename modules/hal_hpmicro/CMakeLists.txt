# Copyright 2022 hpmicro
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_HAS_HPMICRO_HAL)

set(HPM_SDK_BASE ${ZEPHYR_HAL_HPMICRO_MODULE_DIR}/hpm_sdk)
set(HPM_BOARD_DIR ${CONFIG_BOARD})
set(HPM_SOC ${SOC_NAME})
set(ENV{GNURISCV_TOOLCHAIN_PATH} ${SYSROOT_DIR})
add_subdirectory(${ZEPHYR_CURRENT_MODULE_DIR} hal_hpmicro)
endif()
