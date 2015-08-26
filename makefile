# Hey Emacs, this is a -*- makefile -*-
#################################################################
#
# AVR Makefile Template
#
# Based on the sample written by Eric B. Weddington, Jörg Wunsch, et al.
# Released to the Public Domain
#
# Modified by   : Kurt E. Clothier
# Date          : August 26, 2015
#
# Compile       : AVR-GCC
# Supports      : C, no C++ or ASM
#
# More Info     : http://www.projectsbykec.com/
#               : http://www.gnu.org/software/make/
#
#################################################################

#################################################################
#
#------------------- Project Specific Options -------------------
#
#################################################################

# Name of Project (One Word)
PROJECT = lcdReader

# Target file name (without extension).
TARGET = $(PROJECT)_main-v1.0

# List C source files here. 
# Prefix $(SRC_FILES) for each additional source not in project directory.
SRC = $(TARGET).c \

# MCU name... Type: "avrdude -p ?" to get a full listing.
MCU = atmega328p

# Processor frequency.
F_CPU = 1000000

# Fuse Bits (Be Careful)
# Defaults
LFUSE = 0x62
HFUSE = 0xD9
EFUSE = 0x07

# Lock Bits (Be Careful)
LOCKBITS = 0xFD

#################################################################
#
#-------------------- Other Standard Options  -------------------
#
#################################################################

# Programming hardware... Type: "avrdude -c ?" to get a full listing.
AVRDUDE_PROGRAMMER = usbtiny

# com1 = serial port. Use lpt1 to connect to parallel port.
AVRDUDE_PORT = usb

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Additional Libraries to Use (ex. -lNAME for libNAME.a)
LIBS = 

# Other AVRDUDE options
OPTIONS = 
# -B 1024	# This changes the bitrate. Use for SLOW devices, like 31.25kHz.

#################################################################
#
#--------------------- List Extra Directories ------------------- 
#
#################################################################

# Where to find additional included files.
#	Examples: C:/WinAVR/Include or "D:/Path/To/My Directory"
INCLUDE_FILES = .

# Where to find additional library files.
LIBRARY_FILES = $(INCLUDE_FILES)

# Where to find additional source files
SRC_FILES = $(INCLUDE_FILES)
#NOTE: This could case errors because of the ":" in the path
# In that case, use ../../modules to find "Modules" from the working directory

# Object files directory - Use . to put object files in current directory
OBJDIR = .

#################################################################
#
#----------------------------- Flags ----------------------------
#
#################################################################

#---------------- Compiler Options (c)----------------

# Define the MCU type
CFLAGS = -mmcu=$(MCU)
# Generate debugging information
CFLAGS += -g

#----- Optimizer settings -----
# CFLAGS += -O0     # disable optimization (default)
# CFLAGS += -O      # equivalent to -O1
CFLAGS += -O2       # most common optimization setting
# CFLAGS += -O3     # turn on -finline-functions, -funswitch-loops, etc.
# CFLAGS += -fast   # optimize for maximum performance
# CFLAGS += -Os     # optimize for size at the expense of speed.
# CFLAGS += -Oz     # Apple OS X only size optimization setting.

# Define the CPU Frequency
CFLAGS += -DF_CPU=$(F_CPU)UL
# Where to find included files
CFLAGS += -I. -I $(INCLUDE_FILES)
# Tell GCC to pass this to the assembler and create assembler listing
CFLAGS += -Wa,-adhlns=$(<:%.c=$(OBJDIR)/%.lst)
# Set the C Standard to c99 plus GCC extensions
CFLAGS += -std=gnu99
# Make any unqualified char or bitfield types unsigned
CFLAGS += -funsigned-char -funsigned-bitfields
# Pack all structure members together without holes
CFLAGS += -fpack-struct
# Make enum type equivalent to smallest int type which has enough room
CFLAGS += -fshort-enums

#----- Warning Settings -----
# Misnamed, enables a list of warning options, but not all of them.
CFLAGS += -Wall
# Warn for missing prototypes.
CFLAGS += -Wmissing-prototypes
# Warn if a function is declared or defined w/o specifying the argument types.
CFLAGS += -Wstrict-prototypes
# Warn whenever a switch statement does not have a default case.
CFLAGS += -Wswitch-default
# Warn when a switch statement has an index of enumerate type and lacks a case
# for one or more of the named codes in the enumeration, or case labels outside
# the enumeration range.
CFLAGS += -Wswitch-enum
# Warn for a global function defined without a previous prototype.  Issued even
# if the definition itself provides a prototype.
CFLAGS += -Wmissing-declarations
# Warn when a variable is shadowed, or a built-in function is shadowed.
CFLAGS += -Wshadow
# warn of user-supplied include dirs that are missing
CFLAGS += -Wmissing-include-dirs
# warn if precompiled header is found but can't be used
CFLAGS += -Winvalid-pch  

#---------------- Linker Options ----------------

# Where to look for additional library files
LDFLAGS = $(patsubst %,-L%,$(LIBRARY_FILES))
# Include the standard math library
LDFLAGS += -lm $(LIBS)
# Tell GCC to pass this to linker Create Map File, Cross reference to Map file
#LDFLAGS += -Wl,-Map=$(PROJECT).map,--cref

#################################################################
#
#----------------- AVRDUDE Programming Commands -----------------
#
#################################################################

AVRDUDE_WRITE_FLASH = -U flash:w:$(PROJECT).hex
AVRDUDE_WRITE_EEPROM = -U eeprom:w:$(PROJECT).eep
AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) $(OPTIONS)
AVRDUDE_VERBOSE = -v
AVRDUDE_BURN_FUSES = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
AVRDUDE_SET_LOCKS = -U lock:w:$(LOCKBITS):m

#################################################################
#
#----------------- Defining Executable Commands -----------------
#
#################################################################
#CC = avr-gcc
CC = /home/kurt/.colorgcc-avr
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
AR = avr-ar rcs
NM = avr-nm
AVRDUDE = avrdude
REMOVE = rm -f
REMOVEDIR = rm -rf
COPY = cp
WINSHELL = cmd

#################################################################
#
#------------------- Defining Output Messages -------------------
#
#################################################################
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Size before: 
MSG_SIZE_AFTER = Size after:
MSG_COFF = Converting to AVR COFF:
MSG_EXTENDED_COFF = Converting to AVR Extended COFF:
MSG_FLASH = Creating load file for Flash:
MSG_EEPROM = Creating load file for EEPROM:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling C:
MSG_CLEANING = Cleaning project files:
MSG_CREATING_LIBRARY = Creating library:
MSG_LIST_SIZES = Data and function size in ascending order:

#################################################################
#
#----------------- Additional Variable Definitions ---------------
#
#################################################################

# Define all object files.
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 

# Define all listing files.
LST = $(SRC:%.c=$(OBJDIR)/%.lst) 

# Display size of file.
HEXSIZE = $(SIZE) --target=$(FORMAT) $(PROJECT).hex
ELFSIZE = $(SIZE) --mcu=$(MCU) --format=avr $(PROJECT).elf
FUNCSIZE = $(NM) --size-sort $(PROJECT).elf

#################################################################
#
#--------------------- Standard Make Targets --------------------
#
#################################################################

# Compiles program and cleans unnecessary files
all: begin gccversion sizebefore build-all \
listsizes sizeafter clean-most finish end

# Compile the program, default target
build: begin gccversion sizebefore build-all listsizes sizeafter finish end

# Delete all files in directories created during build
clean: begin clean_list_A end

# Delete all files created except .hex file
clean-most: begin clean_list_B end

# Lists detailed information about connected device
information:
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_VERBOSE)

# Program the target device  
program: $(PROJECT).hex 
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)
	
flash: $(PROJECT).hex 
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)

program-eeprom: $(PROJECT).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_EEPROM)

# Burn device fuses
burn-fuses: 
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_BURN_FUSES)
	
# Set device Lock bits
set-locks: 
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_SET_LOCKS)

#################################################################
#
#--------------------- Prerequisite Targets ---------------------
#
#################################################################

build-all: elf hex eep

elf: $(PROJECT).elf
hex: $(PROJECT).hex
eep: $(PROJECT).eep

begin:
	@echo
	@echo $(MSG_BEGIN)
	
finish:
	@echo $(MSG_ERRORS_NONE)

end:
	@echo $(MSG_END)

# Display program size before build
sizebefore:
	@if test -f $(PROJECT).elf; then echo; echo $(MSG_SIZE_BEFORE); $(ELFSIZE); \
	2>/dev/null; echo; fi

# Display program size after build
sizeafter:
	@if test -f $(PROJECT).elf; then echo; echo $(MSG_SIZE_AFTER); $(ELFSIZE); \
	2>/dev/null; echo; fi

# Display sizes of program data and functions
listsizes:
	@if test -f $(PROJECT).elf; then echo; echo $(MSG_LIST_SIZES); $(FUNCSIZE); \
	2>/dev/null; echo; fi

# Display compiler version information.
gccversion : 
	@$(CC) --version

# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	@echo
	@echo $(MSG_FLASH) $@
	$(OBJCOPY) -O $(FORMAT) -R .eeprom -R .fuse -R .lock $< $@

%.eep: %.elf
	@echo
	@echo $(MSG_EEPROM) $@
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings -O $(FORMAT) $< $@ || exit 0

# Create ELF output file from object files.
Link: 
.SECONDARY : $(PROJECT).elf
.PRECIOUS : $(OBJ)
%.elf: $(OBJ)
	@echo
	@echo $(MSG_LINKING) $@
	$(CC) $(CFLAGS) $^ --output $@ $(LDFLAGS)

# Create object files from C source files.
Compile: 
$(OBJDIR)/%.o : %.c
	@echo
	@echo $(MSG_COMPILING) $<
	$(CC) -c $(CFLAGS) $< -o $@ 

# Cleaning List version A
clean_list_A : clean_list_B
	$(REMOVE) $(PROJECT).hex
	
# Cleaning List version B
clean_list_B :
	@echo
	@echo $(MSG_CLEANING)
	$(REMOVE) $(PROJECT).eep
	$(REMOVE) $(PROJECT).cof
	$(REMOVE) $(PROJECT).elf
	$(REMOVE) $(PROJECT).map
	$(REMOVE) $(PROJECT).sym
	$(REMOVE) $(PROJECT).lss
	$(REMOVE) $(SRC:%.c=$(OBJDIR)/%.o)
	$(REMOVE) $(SRC:%.c=$(OBJDIR)/%.lst)
	$(REMOVE) $(SRC:.c=.s)
	$(REMOVE) $(SRC:.c=.d)
	$(REMOVE) $(SRC:.c=.i)
	$(REMOVEDIR) .dep

#################################################################
#
#--------------------- List all Phony Targets -------------------
#
#################################################################

.PHONY : all clean clean-most program build elf hex eep \
build-and-clean begin finish end sizebefore sizeafter listsizes \
gccversion clean_list_A clean_list_B information burn-fuses \
set-locks program-eeprom
