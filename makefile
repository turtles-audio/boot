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
debug: clean
debug: $(DEBUG)/$(NAME).elf

release: CFLAGS += -Os -Werror
release: $(RELEASE)/$(NAME).elf

SOURCES := $(wildcard $(SRC)/*.s $(SRC)/*.c)
OBJECTS :=  $(patsubst $(SRC)/%.s,$(TARGET)/%.o,$(filter %.s,$(SOURCES))) $(patsubst $(SRC)/%.c,$(TARGET)/%.o,$(filter %.c,$(SOURCES)))

$(TARGET)/%.o: $(SRC)/%.s
	@mkdir -p $(TARGET)
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET)/%.o: $(SRC)/%.c
	@mkdir -p $(TARGET)
	$(CC) -c $(CFLAGS) $< -o $@

$(DEBUG)/$(NAME).elf: $(OBJECTS)
	@mkdir -p $(DEBUG)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(DEBUG)/$(NAME).elf

$(RELEASE)/$(NAME).elf: $(OBJECTS)
	@mkdir -p $(RELEASE)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(RELEASE)/$(NAME).elf

clean:
	rm -rf $(TARGET) $(DEBUG) $(RELEASE)

.PHONY: clean debug build release