from serial import Serial

for i in [6, 7, 8]:
	s = Serial("/dev/ttyACM%i" % i, 115200)
	s.write("?\n")

	buf = ""
	while 1:
	  buf += s.read()

	  if buf[-1] == "\n":
	     print(buf)
	     buf = ""
	     s.write("sd10\n")
	     break;
