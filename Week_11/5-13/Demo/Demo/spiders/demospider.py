from scrapy.spider import Spider
from scrapy.http import HtmlResponse

class DemoSpider(Spider):
	name = 'demospider'
	start_urls = 'http://www.sina.com.cn'

	html = HtmlResponse(start_urls)

	filename = html.url.split('/')[-1]
	f = open(filename, 'wb')

	f.write(html.url)
	f.write('\n')
	f.write('\n')

	for k in html.headers:
		f.write(k)
		f.write(' : ')
		f.write(html.headers[k])
		f.write('\n')
	f.write('\n')

	f.write(html.body)
	f.write('\n')

	f.close()
