CC=lcc
ROM=multi.gb
C_FILES=$(wildcard src/*.c)
O_FILES=$(addprefix obj/,$(notdir $(C_FILES:.c=.o)))
H_FILES=$(wildcard src/include/*.h)
LD_FLAGS=
CC_FLAGS=

obj/%.o: src/%.c
	$(CC) -c -o $@ $<

%.gb: obj/%.o $(O_FILES)
	$(CC) -o $@ $<

all: clean $(ROM)

run:
	mednafen $(ROM)

clean:
	-rm -rf *.gb *.o obj/*
