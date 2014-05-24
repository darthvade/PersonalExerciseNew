# encoding: utf-8

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html


from scrapy.item import Item, Field

class NewspiderItem(Item):
    # define the fields for your item here like:
    # name = Field()
	jobid = Field() #jobID全局唯一
	company = Field() #招聘公司
	title = Field() #职位名称
	salary = Field() #职位薪水
	location = Field() #职位工作地点
	experience = Field() #经验要求
	edu_background = Field() #学历要求
	work_time = Field() #工作时间
	job_tempt = Field() #职位诱惑
	repo_time = Field() #职位发布时间
	description = Field() #职位描述

	#页面信息
	page_url = Field() #职位页面URL
