
# Logging

## Tool

  STM32CubeIDE

  Version: 1.4.2
  Build: 7643_20200813_1322 (UTC)

  (C) 2020 STMicroelectronics ALL RIGHTS RESERVED

## Purpose

  This library is integrated in a bigger project and is now being shared to help you going faster through your project.

  It has been used with STM32L476 but should be compatible with any version of STM32L4xx

## Dependencies

  serial - https://github.com/stm32l4xx-packages/serial

## Functionalities

  Several functions to print logs

## Examples

  >> logging.init(uart,(uint32_t)baudrate);

  >> logging.println((char*)"main boot",(char*)"timestamp: ",(long)getTimestamp());
