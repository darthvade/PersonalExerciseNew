#!/usr/bin/python
import os
counter = 63000
while(counter):
	counter = counter - 1
	os.system('./client 127.0.0.1 &')
