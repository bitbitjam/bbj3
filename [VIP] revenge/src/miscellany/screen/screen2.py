#
#	Display test
#
import random
random.seed()

screen = " " * (64*32)
flipIt = 0

def plot(x,y,c = chr(219)):
	global screen,flipIt
	if flipIt != 0:
		x = 63 - x
	p = x+y*64
	screen = screen[:p]+c+screen[p+1:]

def openDoor(i):
	e = i * 8 + 7
	f = i * 8
	for y in range(0,31):
		if y != e/2 and y != 30-e/2:
			for x in range(f,e):
				plot(x,y,'.')

for i in range(0,32):
	for y in range(i/2,31-i/2):
		plot(i,y)
		plot(63-i,y)

for i in range(0,4):
	if random.random() > 0.5:
		flipIt = 0
		openDoor(i)
	if random.random() > 0.5:
		flipIt = 1
		openDoor(i)


for i in range(0,31):
	print(screen[i*64:i*64+64])


