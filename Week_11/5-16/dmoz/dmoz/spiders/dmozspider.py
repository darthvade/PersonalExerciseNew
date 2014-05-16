#coding=utf-8
from scrapy.selector import Selector
from scrapy.spider import Spider
from scrapy.http import Request

class DmozSpider(Spider):
	name = 'dmozspider'
	allowed_domains = []
	start_urls = ['http://www.dmoz.org/World/Chinese_Simplified/']

	def parse(self, response):
		base_url = 'http://www.dmoz.org/'
		sel = Selector(response)
		#filename = response.url.split('/')[-2]
		filename = 'pagelib'
		dirname = '/home/kevin/SpiderData/dmoz/'
		f = file(dirname + filename + '.dat', 'a')

		#向网页库写入网页URL
		f.write('Version:')
		f.write('1.0')
		f.write('\n')

		#向网页库写入网页URL
		f.write('URL:')
		f.write(response.url)
		f.write('\n')

		#向网页库写入HTTP头部信息
			#写入日期
		f.write('Date:')
		f.write(response.headers['Date'])
		f.write('\n')
			#写入数据长度
		f.write('Length:')
		f.write(str(len(response.body)))
		f.write('\n')
		#for head in response.headers:
		#	f.write(head)
		#	f.write(':')
		#	f.write(response.headers[head])
		#	f.write('\n')
		#f.write('\n')
		#f.write('+++++++++++++++++++++++++\n') #DEBUG

		#写入元数据
		#for meta in response.meta:
		#	f.write(meta)
		#	f.write(':')
		#	f.write(str(response.meta[meta]))
		#	f.write('\n')
		#f.write('\n')
		#f.write('+++++++++++++++++++++++++\n') #DEBUG

		#写入网页内容
		f.write('\n')
			#写入网页标题
		title = sel.xpath('//title/text()').extract()
		f.write('Title:')
		for t in title:
			f.write(t.encode("UTF-8"))
			f.write('\n')
		f.write('\n')
			#写入网页内容
		content = sel.xpath('//p/text()|//a/text()').extract()
		f.write('Content:')
		for c in content:
			if len(c) > 0:
				f.write(c.encode("UTF-8"))
				f.write('\n')
		f.write('\n')

		#关闭网页文件
		f.close()

		url = sel.xpath('//@href').re('/World/Chinese_Simplified/.*')
		url = [base_url + elem for elem in url]
		finalurl = sel.xpath('//a[@class=\'listinglink\']/@href').extract()
		for elem in finalurl:
			url.append(elem)
		for neededurl in url:
			yield Request(neededurl)
				
	
