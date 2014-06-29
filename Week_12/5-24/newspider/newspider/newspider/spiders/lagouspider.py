# encoding: utf-8

from scrapy.selector import Selector
from scrapy.spider import Spider
from scrapy.http import Request
from newspider.items import NewspiderItem

jobid = 83661

class NewSpider(Spider):
	name = 'newspider'
	allowed_domains = ['lagou.com']
	start_urls = ['http://www.lagou.com/jobs/83662.html']

	def parse(self, response):
		sel = Selector(response)
		#全局计数
		global jobid
		#基地址
		base_url = 'http://www.lagou.com/jobs/'
		#爬取信息保存单元
		item = NewspiderItem()
		item['jobid'] = jobid #保存jobID（全局唯一）
		item['online'] = sel.xpath('//a[@class=\'inline btn fr btn_apply\']/text() | //a[@class=\'btn fr btn_sended\']/text()').extract() #是否在线
		item['company'] = sel.xpath('//h2[@class=\'fl\']/text()').extract() #保存招聘公司
		item['title'] = sel.xpath('//h1/@title').extract() #保存职位名称
		item['salary'] = sel.xpath('//dd[@class=\'job_request\']/span[1]/text()').extract() #保存职位薪水
		item['location'] = sel.xpath('//dd[@class=\'job_request\']/span[2]/text()').extract() #保存工作地点
		item['experience'] = sel.xpath('//dd[@class=\'job_request\']/span[3]/text()').extract() #保存工作经验
		item['edu_background'] = sel.xpath('//dd[@class=\'job_request\']/span[4]/text()').extract() #保存教育背景
		item['work_time'] = sel.xpath('//dd[@class=\'job_request\']/span[5]/text()').extract() #保存工作时间
		item['job_tempt'] = sel.xpath('//dd[@class=\'job_request\']/text()').extract() #保存职位诱惑
		item['repo_time'] = sel.xpath('//dd[@class=\'job_request\']/div/text()').extract() #保存职位诱惑
		item['description'] = sel.xpath('//dd[@class=\'job_bt\']').extract() #保存职位诱惑


		item['page_url'] = response.url #保存职位页面URL

		#jobID计数
		jobid = jobid + 1
		#返回爬取信息
		yield item
		#返回下一个需要爬取页面的URL
		yield Request(base_url + str(jobid) + '.html')
