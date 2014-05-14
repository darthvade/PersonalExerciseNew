from scrapy.selector import HtmlXPathSelector
from scrapy.spider import BaseSpider
from scrapy.http import Request
#from Demo.items import DemoItem

class MySpider(BaseSpider):
	name = 'wangdaospider'
	allowed_domains = ['cskaoyan.com']
	start_urls = ['http://www.cskaoyan.com']

	def parse(self, response):
		sel = HtmlXPathSelector(response)
		filename = response.url.split('/')[-1]
		dirname = '/home/kevin/SpiderData/wangdao/'
		f = file(dirname + filename, 'wb')	
		f.write(response.body)
		f.close()
		for selurl in sel.select('//a/@href'):
			for subforum in selurl.re('forum-\d{1,5}-\d{1,5}.html|thread-\d{1,6}-\d{1,3}-\d{1,3}.html'):
				if len(subforum) > 0:
						yield Request('http://www.cskaoyan.com/' + subforum)
