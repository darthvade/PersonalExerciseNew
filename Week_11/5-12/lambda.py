#!/usr/bin/python

def repeat(n) :
	return lambda s : s * n

hehe = repeat(5)

print hehe('Jack')
