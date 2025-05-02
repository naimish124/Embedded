MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
LDFLAGS =

SRC = $(wildcard *.c ./Driver/*.c ./RW/*.c ./Display/*.c)
OBJ = $(SRC:.c=.o)
TARGET = main

all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	avrdude -c usbasp -p m32 -U flash:w:$(TARGET).hex

clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).hex

