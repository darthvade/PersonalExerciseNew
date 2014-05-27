import random

class ProxyMiddleware(object):
	def process_request(self, request, spider):
		#request.meta['proxy'] = "http://219.159.199.6:9999"
		ProxyServer = [
			"http://211.144.81.66:18000",
			"http://222.74.6.10:8000",
			"http://211.144.81.68:18000",
			"http://122.226.73.248:80",
			"http://125.93.253.177:3128",
		]
		index = random.randint(0, 4) 
		request.meta['proxy'] = ProxyServer[index]

