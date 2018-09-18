'''
Created on Jul 22, 2018

@author: Administrator
'''

import scrapy
from scrapy import cmdline
from scrapy import selector
from tutorial.items import ImageItem

class picSpider(scrapy.Spider):
    name = 'picSpider'
    allowed_domains = ['27270.com', 'mm131.com']
    start_urls = ['http://www.27270.com/ent/meinvtupian/2017/182294.html', 'http://www.mm131.com/xinggan/4163.html']
    
    def parse(self, response):
        sel = selector.Selector(response)
        sites = sel.xpath('//img/@src').extract()
        items = []
        for each in sites:
            item = ImageItem()
            item['image'] = each
            items.append(item)
        return items
    
if __name__ == '__main__':
    cmdline.execute('scrapy crawl picSpider -o image.xml -t xml'.split())