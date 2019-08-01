#
#	Display test
#
screen = " " * (64*32)
doorDepth = 8
flipIt = 0

def plot(x,y,c = chr(219)):
	global screen,flipIt
	if flipIt != 0:
		x = 63 - x
	p = x+y*64
	screen = screen[:p]+c+screen[p+1:]

def openDoor(p):
	for i in range(p/2,31-p/2):
		plot(p,i)
	global doorDepth
	xm = p-doorDepth
	xm = xm if xm >= 0 else 0
	for i in range(xm,p):
		plot(i,p/2)
		plot(i,31-p/2)
	if p-doorDepth >= 0:
		for i in range(xm/2,31-xm/2):
			plot(xm,i)


for i in range(0,64):
	plot(i,i/2)	
	plot(63-i,i/2)

flipIt = 0
#openDoor(7)
openDoor(15)
#openDoor(23)
openDoor(31)
flipIt = 1
openDoor(7)
#openDoor(15)
openDoor(23)
#openDoor(31)

for i in range(0,31):
	print(screen[i*64:i*64+64])


