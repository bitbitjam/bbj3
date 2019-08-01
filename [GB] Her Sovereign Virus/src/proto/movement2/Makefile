ROM=movement.gb
DEPS=background-data.c\
 herpes-data.c\
 cell-data.c\
 movement.h

%.gb: %.c $(DEPS)
	lcc -o $@ $<

all: $(ROM)

run:
	mednafen $(ROM)

clean:
	-rm -f *.gb *.o
