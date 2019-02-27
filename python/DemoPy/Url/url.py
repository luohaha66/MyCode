'''
Created on Jul 15, 2018

@author: Administrator
'''
import urllib.request
import urllib.parse
import json

def translate():
    content = input('please input:')
    url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'
    head = {}
    head['User_Agent'] = 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36'
    data = {}
    data['i'] = content
    #data['from']='AUTO'
    #data['to']='AUTO'
    #data['smartresult']='dict'
    #data['client']='fanyideskweb'
    #data['salt']='1532145892250'
    #data['sign']='27c4718f4e27085867bf59e1f21aedaa'
    data['doctype']='json'
    #data['version']='2.1'
    #data['keyfrom']='fanyi.web'
    #data['action']='FY_BY_REALTIME'
    #data['typoResult']='false'
    data = urllib.parse.urlencode(data).encode('UTF-8')
    req = urllib.request.Request(url, data, head)
    response = urllib.request.urlopen(req)
    result = json.loads(response.read())
    print('result is %s' % result['translateResult'][0][0]['tgt'])

def proxy():
    url = "http://www.baidu.com"
    pro = urllib.request.ProxyHandler({'high':'39.80.33.145:81'})
    opener = urllib.request.build_opener(pro)
    opener.addheaders = [('User_Agent', 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36')]
    urllib.request.install_opener(opener)
    res = urllib.request.urlopen(url)
    print(res.read())

if __name__ == '__main__':
    proxy()
    
    