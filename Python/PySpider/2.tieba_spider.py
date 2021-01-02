#!/usr/bin/env python
# coding=utf-8

import re
import requests
import os

#https://tieba.baidu.com/f?ie=utf-8&kw=%E8%BF%9B%E5%87%BB%E7%9A%84%E5%B7%A8%E4%BA%BA&fr=search

class TiebaSpier :
    def __init__(self) :
        self.kw = input('please input the keyword : ')
        self.base_url = 'https://tieba.baidu.com/f'
        #self.header = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36 QIHU 360SE'}
        #self.header = { 'User-Agent' : 'Mozilla/5.0.html (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.html.2171.71 Safari/537.36'}
        self.header = {'User-Agent' : 'Mozilla/5.0.html (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.html.1271.64 Safari/537.11'}
        self.title = ''
        self.page_num = 1
        self.img_path = './data/tieba/images'
        if os.path.exists(self.img_path) == False :
            os.makedirs(self.img_path)
        self.txt_path = './data/tieba/text'
        if os.path.exists(self.txt_path) == False :
            os.makedirs(self.txt_path)

    def parse_txt(self, url, params = None) :
        req = requests.get(url, headers = self.header, params = params)
        return req.text

    def parse_byte(self, url, params = None) :
        req = requests.get(url, headers = self.header, params = params)
        return req.content

    def page(self, content) :
        print("the [{}] page is spidering...".format(self.page_num))
        self.page_num += 1
        title_pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".*?".*?>(.+?)</a>.*?')
        url_title = title_pattern.findall(content)
        for url, title in url_title :
            self.title = title
            self.detail('https://tieba.baidu.com' + url)
            self.save_title()
        next_page_pattern = re.compile(r'<a href="(/p/.*?)>.*?下一页.*?</a>.*?')
        next_page = next_page_pattern.findall(content)
        print(next_page)
        if next_page :
            next_page = 'https:' + next_page[0]
            next_content = self.parse_txt(url = next_page)
        else :
            print("the spider end... \n the total [{}] page".format(page_num))

    def detail(self, url) :
        content = self.parse_txt(url =  url)
        img_pattern = re.compile(r'<img class="BDE_Image".*?src="(.*?)".*?')
        urls = img_pattern.findall(content)
        for url in urls :
            print(url)
            self.save_img(url)

    def start(self) :    
        print('the spider is starting...')
        content = self.parse_txt(url = self.base_url, params = {'kw' : self.kw, 'ie' : "utf-8", 'fr' : 'search'})
        print("-------wait--------")
        self.page(content)

    def save_img(self, url) :
        content = self.parse_byte(url = url)
        save_path = self.img_path + '/{}.jpg'.format(self.title)
        with open(save_path, 'wb') as file :
            file.write(content)

    def save_title(self) :
        save_path = self.txt_path + '/tieba_{}.txt'.format(self.kw)
        with open(save_path, 'a', encoding = 'utf-8') as file :
            file.write(self.title)
            file.write('\n')
    
if __name__ == '__main__' :
    spider = TiebaSpier()
    spider.start()