ROM=movement.gb
DEPS=data.c\
 ship.c\
 movement.h

%.gb: %.c $(DEPS)
	lcc -o $@ $<

all: $(ROM)

run:
	pasuspender -- mednafen $(ROM)

clean:
	-rm -f *.gb *.o
