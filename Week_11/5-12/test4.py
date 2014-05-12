#!/usr/bin/python

import urllib
target = 'http://www.baidu.com'
data = urllib.urlopen(target).read()
f = file('baidu.html', 'w')
f.write(data)
f.close()
