#
#		Processor
#
import re

def process(s,opc):
	s = s.replace("@H","R{0:x}".format(opc & 15))
	s = s.replace("@E",str((opc & 3)+1))
	s = s.replace("@P",str(opc & 7))
	s = s.replace("@R",str(opc & 15))
	return s

src = [x if x.find("//") < 0 else x[:x.find("//")] for x in open("1802.def").readlines()]
src = [x.strip().replace("\t"," ") for x in src if x.strip() != ""]
open("__1802_macros.h","w").write("\n".join([x[1:] for x in src if x[0] == ':']))
src = [x for x in src if x[0] != ':']
mnemonics = [None] * 256
code = [None] * 256
mnemonics[0x68] = "nop68"
for l in src:
	m = re.match('^([0-9A-F\\-]+)\\s*\\"(.*)\\"\\s*(.*)$',l)
	assert m is not None,"Error "+l
	r = m.group(1) if len(m.group(1)) == 5 else m.group(1)+"-"+m.group(1)
	for opcode in range(int(r[:2],16),int(r[3:5],16)+1):
		assert mnemonics[opcode] is None,"Duplicate "+l
		mnemonics[opcode] = process(m.group(2),opcode).lower()
		cycles = 2 if (opcode >> 4) != 0xC else 3
		code[opcode] = "Cycles += "+str(cycles)+";"+process(m.group(3),opcode)+";break;"
open("__1802_mnemonics.h","w").write(",".join(['"'+x+'"' for x in mnemonics]))

h = open("__1802_opcodes.h","w")
for i in range(0,256):
	if code[i] is not None:
		h.write("case 0x{0:02x}: /**** {1} ****/\n".format(i,mnemonics[i]))
		x = ["    "+x.strip()+";" for x in code[i].split(";") if x.strip() != ""]
		h.write("\n".join(x)+"\n\n")

h = open("__1802_ports.h","w")
for i in range(1,8):
	h.write("#ifndef INPORT{0}\n#define INPORT{0}() (0)\n#endif\n".format(i))
	h.write("#ifndef OUTPORT{0}\n#define OUTPORT{0}(v) {{}}\n#endif\n".format(i))	
for i in range(1,5):	
	h.write("#ifndef EFLAG{0}\n#define EFLAG{0}() (0)\n#endif\n".format(i))	
h.write("#ifndef OUTPORTQ\n#define OUTPORTQ(old,new) {}\n#endif\n")

print("1802 generation complete.")