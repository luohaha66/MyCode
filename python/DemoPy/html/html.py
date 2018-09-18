'''
Created on Jul 21, 2018

@author: Administrator
'''

import re
import urllib.request
import os
from urllib.error import URLError, HTTPError

def reFunc():
    # result = re.search(r'\d{3}\.\d{3}\.\d{3}', '192.168.110')
    # print(result)
    # res = re.search(r'[asdfg]', 'mmmfff');
    # print(res)
    # a = re.search(r'[01]\d\d|2[0-4]\d|25[0-5]', '255')
    # print(a)
    ip_re = re.compile(r'(([01]{0,1}\d{0,1}\d{0,1}|2[0-4]\d|25[0-5])\.){3}[01]{0,1}\d{0,1}\d{0,1}|2[0-4]\d|25[0-5]')
    ip_res = ip_re.search('0.0.0.0');
    print(ip_res)
    ip_res1 = ip_re.search('255.255.255.255');
    print(ip_res1)
    ip_res2 = ip_re.search('25.25.25.25');
    print(ip_res2)
    ip_res3 = ip_re.search('266.266.266.25');
    print(ip_res3)
    res4 = re.search(r'(love)\1(ha)\2\1', 'lovelovehahalove')
    print(res4)

def openUrl(url):
    html = None
    req = urllib.request.Request(url)
    req.add_header('User_Agent', 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36')
    try:
        html =  urllib.request.urlopen(url)
#     except HTTPError as e:
#         print(e.code)
#     except URLError as e:
#         print(e.reason)
    except URLError as e:
        if hasattr(e, 'reason'):
            print(e.reason)
        elif hasattr(e, 'code'):
            print(e.code)
    else:
        return html.read()

def getImage(html):
    picRe = re.compile(b'"(http://[^"]+[\.jpg|\.png])"')
    resultlist = picRe.findall(html)
    strList = []
    for each in resultlist:
        result = str(each, 'utf-8')
        strList.append(result)
    return strList

def saveImage(dirs, nameList):
    os.mkdir(dirs)
    os.chdir(dirs)
    for each in nameList:
        name = each.split('/')[-1]
        with open(name, 'wb') as f:
            img = openUrl(each)
            f.write(img)


if __name__ == '__main__':
    html = openUrl('http://www.27270.com/ent/meinvtupian/2017/173276_2.html')
    nameList = getImage(html)
    saveImage('xxoo', nameList)
    print('done')


