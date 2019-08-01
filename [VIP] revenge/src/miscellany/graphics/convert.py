from PIL import Image

class GraphicData:
	def __init__(self,count):
		self.count = 0
		self.size = 0
		for i in range(0,count):
			print("    dw __graphic{0:02}".format(i))
	def define(self):
		print("__graphic{0:02}:".format(self.count))
		self.count += 1

	def put(self,data):
		print("    db 0{0:02x}h".format(data))
		self.size += 1

class Graphic:
	def __init__(self,graphic):
		gfx = Image.open(graphic)
		self.height = gfx.size[1]
		assert gfx.size[0] == 8
		self.imageData = []
		for y in range(0,self.height):
			self.imageData.append(["."] * 8)
			for x in range(0,8):
				p = gfx.getpixel((x,y))
				t = p[0]+p[1]+p[2]
				if t == 0:
					self.imageData[y][x] = ' '
				if t == 255*3:
					self.imageData[y][x] = 'X'

	def show(self):
		for r in self.imageData:
			print (";        "+"".join(r))

	def render(self,data,x,y,reverse):
		data.put(x + y * 8)
		for y in range(0,self.height):
			mask = 0x00
			pic = 0x00
			for x in range(0,8):
				t = self.imageData[y][x]
				bit = 0x80 >> x if not reverse else 0x01 << x
				if t == '.':
					mask = mask | bit 
				if t == ' ':
					pic = pic | bit
			assert mask != 0xFF
			data.put(mask)
			data.put(pic)
		data.put(0xFF)

data = GraphicData(6)

for i in range(1,4):
	g = Graphic("princess{0}.png".format(i))
	g.show()
	data.define()
	g.render(data,3,32-i*4-g.height,False)
	data.define()
	g.render(data,4,32-i*4-g.height,True)
#for i in range(1,5):
#	g = Graphic("heart{0}.png".format(i))
#	g.show()
#	data.define()
#	g.render(data,6,5-g.height/2,False)
#	data.define()
#	g.render(data,7,5-g.height/2,True)

print("; {0}".format(data.size))