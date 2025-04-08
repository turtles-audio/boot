NAME := boot

# Directories
SRC := src
DRIVER := $(SRC)/driver
CORE := $(SRC)/core
TARGET := target
OBJ := $(TARGET)/obj
DEBUG := $(TARGET)/debug
RELEASE := $(TARGET)/release

# Compiler
CC := arm-none-eabi-gcc
LINK=$(SRC)/image.ld

CWARN := -Wall -Wextra
CWARN += -Wshadow -Wundef -Wcast-align
CWARN += -Wswitch-enum -Wunreachable-code
CWARN += -Wformat=2 -Wformat-nonliteral -Wformat-security
CWARN += -Wpointer-arith -Wredundant-decls

CFLAGS := $(CWARN) -mcpu=cortex-m7 -T$(LINK)
CFLAGS += -nostdlib -nostartfiles -nostdinc
CFLAGS += -zmax-page-size=0x100

default: all
build: clean release

debug: CFLAGS += -g -Og
debug: $(DEBUG)/$(NAME).elf

release: CFLAGS += -Os -Werror -s -static
release: $(RELEASE)/$(NAME).elf

SOURCES := $(wildcard $(SRC)/*.s $(SRC)/*.c $(DRIVER)/*.c $(CORE)/*.c)
OBJECTS := $(patsubst $(SRC)/%.s,$(OBJ)/%.o,$(wildcard $(SRC)/*.s)) \
		   $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(wildcard $(SRC)/*.c)) \
		   $(patsubst $(DRIVER)/%.c,$(OBJ)/%.o,$(wildcard $(DRIVER)/*.c)) \
		   $(patsubst $(CORE)/%.c,$(OBJ)/%.o,$(wildcard $(CORE)/*.c))

$(TARGET):
	-mkdir "$(TARGET)"

$(RELEASE): $(TARGET)
	-mkdir "$(RELEASE)"

$(DEBUG): $(TARGET)
	-mkdir "$(DEBUG)"

$(OBJ): $(TARGET)
	-mkdir "$(OBJ)"

$(OBJ)/%.o: $(SRC)/%.s $(OBJ)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ)/%.o: $(DRIVER)/%.c $(OBJ)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ)/%.o: $(CORE)/%.c $(OBJ)
	$(CC) -c $(CFLAGS) $< -o $@


$(DEBUG)/$(NAME).elf: $(OBJECTS) $(DEBUG)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(DEBUG)/$(NAME).elf

$(RELEASE)/$(NAME).elf: $(OBJECTS) $(RELEASE)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(RELEASE)/$(NAME).elf

clean:
	-rmdir /s /q $(TARGET)

all: clean release
	-rmdir /s /q "$(OBJ)"
	make debug

help:
	@echo Usage: make [target1] [target2] ...
	@echo Targets:
	@echo   all       - Build all targets (default)
	@echo   build     - Release alias
	@echo   release   - Build release version
	@echo   debug     - Build debug version
	@echo Commands:
	@echo   clean     - Clean up build files
	@echo   help      - Show this help message

.PHONY: help default all build debug release build