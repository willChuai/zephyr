# Copyright 2022 hpmicro
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(${CONFIG_SOC})

zephyr_sources(
  start.S
  soc.c
)

if(CONFIG_SOC_ANDES_V5_HWDSP)
  zephyr_cc_option(-mext-dsp)
endif()
