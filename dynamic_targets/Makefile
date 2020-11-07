# Declare default C and CPP flags.
CFLAGS       = -g
CPPFLAGS     = -DDEBUG

# Declare the name and sources for out first artefact.
FOO_NAME     = foo
FOO_SOURCES  = foo.c

# Declare the name and sources for out second artefact.
BAR_NAME     = bar
BAR_SOURCES  = bar.c

# Add more artefacts following the above format.

# Generate a list of artefact identifiers, i.e the name preceding the underscore in the variables for each of
# the above targets.
PROGRAMS     = $(patsubst %_SOURCES,%,$(filter %_SOURCES,$(.VARIABLES)))

# This function generates build rules for the supplied artefact identifier.
define generate
    # Generate a list of objects for the specified artefact identifier.
    $(1)_OBJECTS := $($(1)_SOURCES:.c=.o)

    # Generate the target name for the artefact identifier.
    $(1)_EXE     := $($(1)_NAME)

    # Add the target to the list of default targets. Note the double dolar sybmol, this is to escape the
    # variable in order to provent it being evaluation as the function is parsed but rather when the output of
    # the function is evaluated.
    all: $$($(1)_EXE)

    # Specify the target rule and receipe for the specified artefact identifier.
    $$($(1)_EXE): $$($(1)_OBJECTS)
		$$(CC) $$(CFLAGS) $$(CPPFLAGS) -o $$@ $$^

    # Add a custom 'clean' rule to the default clean target.
    clean: clean-$(1)

    # Specify the custom clean rule.
    clean-$(1):
		$$(RM) $$($(1)_EXE) $$($(1)_OBJECTS)
endef

# For each of the declared artefacts, generate rules to build it.
$(foreach TARGET,$(PROGRAMS),$(eval $(call generate,$(TARGET))))

.PHONY: all clean
