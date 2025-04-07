NAME := bootv7

CC := arm-none-eabi-gcc
LINK=boot.ld
CWARN := -Wall -Wextra
CFLAGS := $(CWARN) -nostdlib -mcpu=cortex-m7 -T$(LINK)

# Directories
SRC := src
TARGET := target
DEBUG := $(TARGET)/debug
RELEASE := $(TARGET)/release

build: clean release

debug: CFLAGS += -g -Og
debug: $(DEBUG)/$(NAME).elf

release: CFLAGS += -Os -Werror
release: $(RELEASE)/$(NAME).elf

SOURCES := $(wildcard $(SRC)/*.s $(SRC)/*.c)
OBJECTS :=  $(patsubst $(SRC)/%.s,$(TARGET)/%.o,$(filter %.s,$(SOURCES))) $(patsubst $(SRC)/%.c,$(TARGET)/%.o,$(filter %.c,$(SOURCES)))

$(RELEASE):
	mkdir "$(RELEASE)"

$(DEBUG):
	mkdir "$(DEBUG)"

$(TARGET):
	mkdir "$(TARGET)"

$(TARGET)/%.o: $(SRC)/%.s $(TARGET)
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET)/%.o: $(SRC)/%.c $(TARGET)
	$(CC) -c $(CFLAGS) $< -o $@

$(DEBUG)/$(NAME).elf: $(OBJECTS) $(DEBUG)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(DEBUG)/$(NAME).elf

$(RELEASE)/$(NAME).elf: $(OBJECTS) $(RELEASE)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(RELEASE)/$(NAME).elf

clean:
	-rmdir /q /s $(TARGET)

.PHONY: clean debug build release