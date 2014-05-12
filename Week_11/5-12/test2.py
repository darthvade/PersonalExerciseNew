#!/usr/bin/python

import cPickle

filename = 'data'

heh = ('Kevin', 'Nore', 'Jicky')

f = file(filename, 'w');

cPickle.dump(heh, f)

f.close();

f = file(filename)

newTule = cPickle.load(f);

print newTule
