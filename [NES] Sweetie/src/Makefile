CC65_PREFIX:=/opt/cc65
CC:=$(CC65_PREFIX)/bin/cc65
AS:=$(CC65_PREFIX)/bin/ca65
LD:=$(CC65_PREFIX)/bin/ld65
CFLAGS:=-I$(CC65_PREFIX)/include -Iinclude -O -Os -Oi -Or
ASFLAGS:=-I$(CC65_PREFIX)/asminc
LDLIBS:=$(CC65_PREFIX)/lib/nes.lib

all: sweetie.nes

sweetie.nes: crt0.o gnes.o bullets.o character.o princess.o alien.o sweetie.o $(LDLIBS)

crt0.o: crt0.s data/tileset.chr data/*.pal

%.nes: %.o
	$(LD) --config nes.cfg -o $@ $^

%.o: %.c
%.o: %.s
	$(AS) -t nes $(ASFLAGS) -o $@ $<

%.s: %.c
	$(CC) -t nes $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

distclean: clean
	rm -f *.nes

.PHONY: all clean distclean
