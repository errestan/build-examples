PYTHON := python3

all: foo bar

foo: foo.c foo.h
	$(CC) -o $@ $<

foo.h: foo.txt
	$(PYTHON) foo.py $< $@
foo.h: .EXTRA_PREREQS = foo.py

bar: bar.c bar.h
	$(CC) -o $@ $<

bar.h: bar.txt
	$(PYTHON) bar.py $< $@
bar.h: .EXTRA_PREREQS = bar.py

clean:
	-$(RM) foo foo.h bar bar.h

.PHONY: all clean
