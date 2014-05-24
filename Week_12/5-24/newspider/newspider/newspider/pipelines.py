#coding=utf-8

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html

import re
import MySQLdb

class NewspiderPipeline(object):
	def __init__(self):
		self.conn = MySQLdb.connect(host='localhost', user='root', passwd='zpcx19901231', db='LagouDB', port=8800, charset='utf8')
		self.conn.select_db('LagouDB')
		self.cur = self.conn.cursor()
	def __del__(self):
		self.cur.close()
		self.conn.close()
	def process_item(self, item, spider):
		#保存需要的页面信息
		if None != re.match('http://www.lagou.com/jobs/.*.html', item['page_url']):
			#数据存储
			#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			#CSV存储
			#flagou = file('/home/kevin/SpiderData/lagou/log.data', 'a')
			#flagou.write(str(item['jobid']) + '\n')
			#flagou.write(item['company'][0].encode('utf-8').strip() + '\t')
			#flagou.write(item['title'][0].encode('utf-8') + '\t')
			#flagou.write(item['salary'][0].encode('utf-8') + '\t')
			#flagou.write(item['location'][0].encode('utf-8') + '\t')
			#flagou.write(item['experience'][0].encode('utf-8') + '\t')
			#flagou.write(item['edu_background'][0].encode('utf-8') + '\t')
			#flagou.write(item['work_time'][0].encode('utf-8') + '\t')
			#flagou.write(item['job_tempt'][5].encode('utf-8').strip().decode('utf-8')[6:].encode('utf-8') + '\t')
			#flagou.write(item['repo_time'][0].encode('utf-8').strip().decode('utf-8')[5:].encode('utf-8') + '\t')
			#flagou.write(item['description'][0].encode('utf-8').strip() + '\t')
			#flagou.write(item['page_url'] + '\n')
			#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			#数据库（MySql存储）
			values = []
			values.append(str(item['jobid']))
			values.append(item['company'][0].encode('utf-8').strip())
			values.append(item['title'][0].encode('utf-8'))
			values.append(item['salary'][0].encode('utf-8'))
			values.append(item['location'][0].encode('utf-8'))
			values.append(item['experience'][0].encode('utf-8'))
			values.append(item['edu_background'][0].encode('utf-8'))
			values.append(item['work_time'][0].encode('utf-8'))
			values.append(item['job_tempt'][5].encode('utf-8').strip().decode('utf-8')[6:].encode('utf-8'))
			values.append(item['repo_time'][0].encode('utf-8').strip().decode('utf-8')[5:].encode('utf-8'))
			values.append(item['description'][0].encode('utf-8').strip())
			values.append(item['page_url'])
			self.cur.execute('insert into RawTable values(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)', values)
			self.conn.commit()

		return item
