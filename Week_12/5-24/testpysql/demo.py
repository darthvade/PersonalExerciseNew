#!/usr/bin/python
# encoding: utf-8

import MySQLdb

conn = MySQLdb.connect(host='localhost', user='root', passwd='zpcx19901231', port=8800, charset='utf8')
cur = conn.cursor()

conn.select_db('test')

cur.execute('insert into pythondb values (5, \'title 添加新文字\')')
conn.commit()

num = cur.execute('select * from pythondb')
conn.commit()

result = cur.fetchmany(num)

print result

cur.close()
conn.close()


