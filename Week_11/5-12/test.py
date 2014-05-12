#!/usr/bin/python

doc = u'string that i want to print'

f = file('./output', 'w')
f.write(doc)
f.close()
