# 📟 Embedded System Application

## Overview

This project is a modular embedded system application written in C, designed to interface with various hardware peripherals such as temperature sensors, real-time clocks (RTC), analog-to-digital converters (ADC), EEPROM, and display modules (LCD/UART). It showcases a structured approach to embedded software development using driver abstraction and layered design.

## Features

- LCD and UART display support
- Temperature sensor integration
- RTC read and AM/PM formatting
- EEPROM write operation
- Analog data acquisition via ADC
- External interrupt support
- Modular driver architecture (I2C, SPI, UART, etc.)

## File Structure

```
Embedded/
├── main.c                # Main control loop
├── header.h              # Global declarations and macros
├── delay.c               # Timing functions
├── log.c                 # Logging utilities
├── temp.c                # Temperature handling logic
├── rtc_ampm.c            # RTC time formatting
├── test.c                # Test routines

├── Driver/
│   ├── i2c_driver.c
│   ├── spi_driver.c
│   ├── uart_driver.c
│   ├── lcd_driver.c
│   ├── temp_driver.c
│   └── interrupt_driver.c

├── RW/
│   ├── ADC_read.c
│   ├── TEMP_read.c
│   ├── RTC_read.c
│   └── EEPROM_write.c

├── Display/
│   ├── LCD_display.c
│   ├── UART_display.c
```

## How It Works

The core logic is located in `main.c`:

```c
void main() {
    lcd_init();         // Initialize LCD
    uart_init();        // Initialize UART
    exintr_en();        // Enable external interrupt (EINT0)
    temp_init();        // Initialize temperature sensor
    delay(250);         // Startup delay

    while (1) {
        RTC_read();         // Read current time
        TEMP_read();        // Read temperature
        ADC_read();         // Read analog data
        EEPROM_write();     // Store data to EEPROM
        LCD_display();      // Output to LCD
    }
}
```

Each function in the loop delegates to modules in the `/RW/` and `/Display/` directories, which further use lower-level drivers from `/Driver/`.

## Getting Started

### Prerequisites
- A microcontroller with I2C, SPI, UART, and ADC support (e.g., ATmega series)
- LCD screen
- Temperature sensor (e.g., LM35)
- RTC chip (e.g., DS1307)
- EEPROM chip
- Embedded C compiler (e.g., avr-gcc)
- Programmer and flashing tool (e.g., USBasp)

### Build & Flash
1. Clone the repository
2. Compile with a suitable Makefile or manually with `avr-gcc`
3. Flash to your microcontroller using your preferred uploader

## To-Do / Improvements

- Add configuration file for adjustable sensor parameters
- Fix the `UART_diaplay.c` filename typo
- Add comments to driver source files
- Modularize EEPROM read functionality
- Add support for RTC setting via UART commands

## License

This project is open-source and available under the MIT License.
