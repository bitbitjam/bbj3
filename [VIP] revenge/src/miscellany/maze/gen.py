
import random

class LFSR:
	def __init__(self,preGet = 0):
		self.seed = 0xACE1
		while preGet > 0:
			preGet-=1
			self.get()

	def get(self,mask = 1):
		lsb = self.seed & 1;
		self.seed = self.seed >> 1;
		if lsb != 0:
			self.seed ^= 0xB400
		n = self.seed
		if (self.seed & 0x80) != 0:
			n += 1
		return n & mask

def fill(maze,pos):
	if maze[pos] == '!':
		maze[pos] = ' '
		fill(maze,pos-1)
		fill(maze,pos+1)
		fill(maze,pos-16)
		fill(maze,pos+16)

def doMaze(sr):
	maze = ['X'] * 256
	for p in range(17,223):														# range of maze
		if (p & 0xF) != 0xF:													# do not overwrite right edge (left done by next)
			if (p & 0x11) == 0x11:												# makes a checkerboard pattern.
				maze[p] = '!'
				if sr.get(15) < 11:												# randomly open southbound or eastbound exit.
					maze[p+1] = '!'
				if sr.get(15) < 11:
					maze[p+16] = '!'

	fill(maze,7*16+7)
	maze[7*16+7] = '*'

	for i in range(0,16):
		print("".join(maze[i*16:i*16+16]))
	print("")

doMaze(LFSR())

c = LFSR()
print("{0:04x}".format(c.seed))
for i in range(0,8):
	r = c.get(255)
	s = c.seed
	print("{0:04x} {1:02x}".format(s,r))
