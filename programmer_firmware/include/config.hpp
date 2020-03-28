#pragma once

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>

// To try and makes this firmware adaptable to other use cases, the IO defines
// for all peripherals have been broken out here for easier meddling.

namespace config {

// Direct FPGA interface
static const rcc_periph_clken fpga_en_rcc = RCC_GPIOB;
static const uint32_t fpga_en_port = GPIOB;
static const uint32_t fpga_en_pin = GPIO10;

// Flash chip IO configuration
static const uint32_t bitstream_flash_spi{SPI1};
static const rcc_periph_clken bitstream_flash_spi_rcc{RCC_SPI1};
static const uint32_t bitstream_flash_spi_port{GPIOA};
static const uint16_t bitstream_flash_spi_pins{GPIO5 | GPIO6 | GPIO7};
static const uint8_t bitstream_flash_spi_af{GPIO_AF0};

// UART (bridged to USB CDC-ACM endpoint)
static const uint32_t fpga_uart = USART1;
static const rcc_periph_clken fpga_uart_rcc = RCC_USART1;
static const uint8_t fpga_uart_irq = NVIC_USART1_IRQ;
static const uint32_t fpga_uart_port = GPIOB;
static const uint16_t fpga_uart_pins = GPIO6 | GPIO7;
static const uint8_t fpga_uart_af = 0;
static const uint32_t fpga_uart_baudrate = 2'000'000;

// USB vendor / product information
static const uint16_t usb_id_vendor = 0x1209;
static const uint16_t usb_id_product = 0xf002;
static const uint16_t usb_id_bcd_device_revision = 0x0200;
// USB Strings
static const char *usb_string_manufacturer = "Ross Schlaikjer";
static const char *usb_string_product = "FPGA Bitstream Programmer";

} // namespace config
