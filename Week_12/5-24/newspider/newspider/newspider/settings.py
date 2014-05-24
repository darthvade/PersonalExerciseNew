# Scrapy settings for newspider project
#
# For simplicity, this file contains only the most important settings by
# default. All the other settings are documented here:
#
#     http://doc.scrapy.org/en/latest/topics/settings.html
#

BOT_NAME = 'newspider'

SPIDER_MODULES = ['newspider.spiders']
NEWSPIDER_MODULE = 'newspider.spiders'
ITEM_PIPELINES = {
	'newspider.pipelines.NewspiderPipeline': 1				
}

# Crawl responsibly by identifying yourself (and your website) on the user-agent
#USER_AGENT = 'newspider (+http://www.yourdomain.com)'
