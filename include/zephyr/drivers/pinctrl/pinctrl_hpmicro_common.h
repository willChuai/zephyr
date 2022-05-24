/*
 * Copyright 2022 hpmicro
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef ZEPHYR_INCLUDE_DRIVERS_PINCTRL_PINCTRL_HPMICRO_COMMON_H_
#define ZEPHYR_INCLUDE_DRIVERS_PINCTRL_PINCTRL_HPMICRO_COMMON_H_

#define HPMICRO_PAD_NUM(_mux)\
(((_mux) >> HPMICRO_PIN_NUM_SHIFT) & HPMICRO_PIN_NUM_MASK)

#define HPMICRO_FUNC_ANALOG(_mux)\
(((_mux) >> HPMICRO_PIN_ANALOG_SHIFT) & HPMICRO_PIN_ANALOG_MASK)

#define HPMICRO_FUNC_ALT_SELECT(_mux)\
(((_mux) >> HPMICRO_PIN_ALT_SHIFT) & HPMICRO_PIN_ALT_MASK)

#define HPMICRO_FUNC_LOOPBACK(_cfg)\
(((_cfg) >> HPMICRO_FORCE_INPUT_SHIFT) & HPMICRO_FORCE_INPUT)

#define HPMICRO_PAD_CTL_MS(_cfg)\
(((_cfg) >> HPMICRO_POWER_SHIFT) & HPMICRO_POWER)

#define HPMICRO_PAD_CTL_OD(_cfg)\
(((_cfg) >> HPMICRO_OPEN_DRAIN_SHIFT) & HPMICRO_OPEN_DRAIN)

#define HPMICRO_PAD_CTL_SMT(_cfg)\
(((_cfg) >> HPMICRO_SCHMITT_ENABLE_SHIFT) & HPMICRO_SCHMITT_ENABLE)

#define HPMICRO_PAD_CTL_PULL_UP(_cfg)\
(((_cfg) >> HPMICRO_PULL_UP_SHIFT) & HPMICRO_PULL_UP)

#define HPMICRO_PAD_CTL_PULL_DN(_cfg)\
(((_cfg) >> HPMICRO_PULL_DOWN_SHIFT) & HPMICRO_PULL_DOWN)

#define HPMICRO_PAD_CTL_PS(_cfg)\
HPMICRO_PAD_CTL_PULL_UP(_cfg)

#define HPMICRO_PAD_CTL_PE(_cfg)\
((!(((_cfg) >> HPMICRO_NO_PULL_SHIFT) & HPMICRO_NO_PULL)) & \
(HPMICRO_PAD_CTL_PULL_UP(_cfg) ^ HPMICRO_PAD_CTL_PULL_DN(_cfg)))

#define HPMICRO_PAD_CTL_DS(_cfg)\
(((_cfg) >> HPMICRO_DRIVER_STRENGTH_SHIFT) & HPMICRO_DRIVER_STRENGTH)

#endif /* ZEPHYR_INCLUDE_DRIVERS_PINCTRL_PINCTRL_HPMICRO_COMMON_H_ */
