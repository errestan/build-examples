BUILD_DIR  = build

CFLAGS     = -fPIC
CPPFLAGS   = -I$(EXTENSION_INC)
LDFLAGS    = -shared

EXTENSION        = my_extension
EXTENSION_DIR   := $(BUILD_DIR)/extension
EXTENSION_INC    = extension/include
EXTENSION_SRC   := $(wildcard extension/*.c)
EXTENSION_OBJ    = $(EXTENSION_SRC:.c=.o)
EXTENSION_LIB    = $(EXTENSION_DIR)/$(EXTENSION).so

all:
	@echo Upper Case: $(to-upper HeLlO WoRld)
	@echo Lower Case: $(to-lower HeLlO WoRld)

clean:
	-rm -rf $(BUILD_DIR)

$(EXTENSION_LIB): $(EXTENSION_OBJ) | $(EXTENSION_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

$(EXTENSION_DIR):
	@mkdir -p $@

# Load our custom extension shared object.
-load $(EXTENSION_LIB)

.PHONEY: all
