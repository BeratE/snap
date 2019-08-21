# General Config
TARGET 		:= snap

MEMORY_MAP	:= src/memmap.cfg
LOG_FILE	:= ass.log

# Directory structure
SRC_DIR		:= src
RES_DIR		:= res
OBJ_DIR		:= obj
BIN_DIR 	:= bin

# File types
IMG_SFX		:= png		# Image resource type
TGT_SFX		:= sfc		# Target 

# Assembler/Linker configs
AS65		:= ca65		# Assembler/Compiler
LD65		:= ld65		# Linker
PLATFORM	:= 65816	# Target CPU
LFLAGS		:= 
AFLAGS		:= -v -v -v

# --------------------------------------------------------------------------
SOURCE_FILES	:= $(shell find $(SRC_DIR) -type f -name *.s)
OBJECT_FILES	:= $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SOURCE_FILES:.s=.o))
INCLUDE_FILES	:= $(shell find $(RES_DIR) -type f -name *.inc)
IMAGE_FILES	:= $(shell find $(RES_DIR) -type f -name *.$(IMG_SFX))

.PHONY: all clean cleanall rebuild resources directories

all: resources $(TARGET)

test: all
	@bsnes-compatibility $(BIN_DIR)/$(TARGET).$(TGT_SFX) 

clean:
	@rm -rf $(OBJ_DIR)

cleanall: clean
	@rm -rf $(BIN_DIR)

rebuild: cleanall all

resources: directories
	@echo **Building Resource Files ..
	$(foreach img, $(IMAGE_FILES), @png2snes --bitplanes 4		\
	--tilesize 8 --binary --output=$(notdir $(basename $(img)))	\
	$(img))
	@mv *.cgr *.vra src/

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Real build targets
$(TARGET): $(OBJECT_FILES) $(INCLUDE_FILES)
	@echo **Linking Target $@ ..
	@$(LD65) $(LFLAGS) -C $(MEMORY_MAP) $^ -o $(BIN_DIR)/$@.$(TGT_SFX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@echo  **Assembling $< ..
	@$(AS65) $(AFLAGS) --cpu $(PLATFORM) -o $@ $< > $(LOG_FILE)
