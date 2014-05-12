#!/usr/bin/python

mylist = ['Kevin', 'Norekk', 'hehell']

newlist  = [i + 'add by for' for i in mylist if len(i) > 5]

print newlist
