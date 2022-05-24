.. _hpm6750evkmini:

HPMicro HPM6750EVKMINI
######################

Overview
********

The HPM6750 is a dual-core flashless MCU running 816Mhz.
It has a 2MB continuous on-chip ram.
Also, it provides various memory interfaces, including SDRAM, Quad SPI NOR Flash, SD/eMMC.

The figure shows the PCB is HPM6750EVKmini platform.

.. image:: img/hpm6750evkmini.png
     :align: center
     :alt: HPM6750EVKMINI

Hardware
********

The HPM6750EVKMINI platform integrates 2 cores 32-bit 816MHz RISC-V CPUs, DSP,
2M RAM, Cache, SPI flash memory, ethernet controller and other peripherals.

- HPM6750IVM MCU (816Mhz, 2MB OCRAM)
- Onboard Memory
  - 128Mb SDRAM
  - 64Mb Quad SPI NOR Flash
- Display & Camera
  - LCD connector
  - Camera (DVP)
- WiFi
  - RW007 over SPI
- USB
  - USB type C (USB 2.0 OTG) connector x2
- Audio
  - Mic
  - DAO
- Others
  - TF Slot
  - FT2232
  - Beeper
  - RGB LED
- Expansion port
  - ART-PI extension port

Serial Port
===========

The HPM6750EVKMINI platform has 2 UARTs.
The Zephyr console output is by default assigned to UART0 and the default
settings are 115200 8N1.

Programming and debugging
*************************

Building
========

You can build applications in the usual way. Here is an example for
the :ref:`hello_world` application.

.. zephyr-app-commands::
   :board: hpm6750evkmini
   :goals: build

Flashing
========

 ``CONFIG_XIP=n``, you can load the program (``zephyr.elf``) into RAM directly and execute it.

.. code-block:: console

   openocd -f boards/riscv/hpm6750evkmini/support/probes/ft2232.cfg \
   -f boards/riscv/hpm6750evkmini/support/soc/hpm6750-single-core.cfg \
   -f boards/riscv/hpm6750evkmini/support/boards/hpm6750evkmini.cfg

   riscv64-zephyr-elf-gdb zephyr/zephyr.elf
   (gdb) target remote localhost:3333
   (gdb) monitor reset halt
   (gdb) load
   (gdb) quit

Open a serial terminal with the following settings:

- Speed: 115200
- Data: 8 bits
- Parity: None
- Stop bits: 1

you should see the following message in the terminal:

.. code-block:: console

   Hello World! hpm6750evkmini

Debugging
=========

.. code-block:: console

   openocd -f boards/riscv/hpm6750evkmini/support/probes/ft2232.cfg \
   -f boards/riscv/hpm6750evkmini/support/soc/hpm6750-single-core.cfg \
   -f boards/riscv/hpm6750evkmini/support/boards/hpm6750evkmini.cfg

   ./riscv64-zephyr-elf-gdb zephyr/zephyr.elf
   (gdb) target remote localhost:3333
   (gdb) monitor reset halt
   (gdb) load
