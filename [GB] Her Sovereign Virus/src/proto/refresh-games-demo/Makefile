ROM=demo.gb

%.gb: %.c
	lcc -o $@ $<

all: $(ROM)

run:
	pasuspender -- mednafen $(ROM)

clean:
	-rm -f *.gb *.o
