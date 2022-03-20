#创建删除
def eg19():
    a_tuple = ('a', )
    print(a_tuple)
    a_tuple = ('a', 'b', 'mpilgrim', 'z', 'example')
    print(a_tuple)
    a=3
    print(a)
    a=3,
    print(a)
    x = () #空元组
    print(x)
    print(tuple('abcdefg'))
    aList=[-1, -4, 6, 7.5, -2.3, 9, -11]
    print(tuple(aList))
    s = tuple() #空元组
    print(s)

#序列解包
##多变量赋值
def eg20():
    v_tuple = (False, 3.5, 'exp')
    (x, y, z) = v_tuple
    print(x,y,z)
    a=[1,2,3]
    b,c,d=a
    print(b,c,d)
    s={'a':1,'b':2,'c':3}
    b,c,d=s
    print(b,c,d)

##序列遍历
def eg21():
    keys=['a','b','c','d']
    values=[1,2,3,4]
    for k,v in zip(keys,values):
        print(k,v)
    aList = [1,2,3]
    bList = [4,5,6]
    cList = [7,8,9]
    dList = zip(aList, bList, cList)
    for index, value in enumerate(dList):
        print(index, ':', value)

#生成器推导式
def eg22():
    g=((i+2)**2 for i in range(10))
    print(g)
    print(tuple(g))
    print(tuple(g))
    g=((i+2)**2 for i in range(10))
    print(g.__next__())
    for i in g:
        print(i,end=' ')

#12字典
##创建删除
def eg23():
    #赋值
    a_dict = {'server': 'db.diveintopython3.org', 'database': 'mysql'}
    print(a_dict)
    x = {} #空字典
    print(x)
    #已有数据
    keys=['a','b','c','d']
    values=[1,2,3,4]
    dictionary=dict(zip(keys,values))
    print(dictionary)
    x = dict() #空字典
    print(x)
    #dict
    d=dict(name='Dong',age=37)
    print(d)
    #给定键
    adict=dict.fromkeys(['name','age','sex'])
    print(adict)

##元素读取
def eg24():
    #下标
    aDict={'name':'Dong', 'sex':'male', 'age':37}
    print(aDict['name'])
    #get
    print(aDict.get('address'))
    print(aDict.get('address', 'SDIBT'))
    aDict['score'] = aDict.get('score',[])
    aDict['score'].append(98)
    aDict['score'].append(97)
    print(aDict)                               

def eg25():
    #items,keys,values
    aDict={'name':'Dong', 'sex':'male', 'age':37}
    for item in aDict.items():
        print(item)
    for key in aDict:
        print(key)
    for key, value in aDict.items():
        print(key, value)
    print(aDict.keys())
    print(aDict.values())

def eg26():
    ##添加修改
    aDict={'name':'Dong', 'sex':'male'}
    #添加1
    aDict['age'] = 38
    print(aDict)
    aDict['address'] = 'SDIBT'
    print(aDict)
    #添加2
    aDict.items()
    aDict.update({'a':'a','b':'b'})
    print(aDict)

##字典应用
#生成包含1000个字符的随机字符串统计字符出现次数。
#method1
def func8():
    import string
    import random
    x = string.digits #+ string.ascii_letters + string.punctuation
    print(x)
    y = [random.choice(x) for i in range(200)]
    print(y)
    z = ''.join(y)
    print(z)
    d = dict()
    for ch in z:
        d[ch] = d.get(ch, 0) + 1
    print(d)
                               
#method2
def func81():
    import string
    import random
    x = string.digits
    y = [random.choice(x) for i in range(200)]
    z = ''.join(y)
    from collections import defaultdict
    frequences = defaultdict(int)
    print(frequences)
    for item in z:
        frequences[item] += 1
    print(frequences.items())
                               
#method3
def func82():
    import string
    import random
    x = string.digits
    y = [random.choice(x) for i in range(200)]
    z = ''.join(y)
    from collections import Counter
    frequences = Counter(z)
    print(frequences.items())
    print(frequences.most_common(1))
    print(frequences.most_common(3))
                               
#Counter词频统计
def func9():
    from collections import Counter
    cnt = Counter()
    for word in ['red', 'blue', 'red', 'green', 'blue', 'blue']:
        cnt[word] += 1
    print(cnt)

#有序字典
def func10():
    ##无序例
    x = dict() 
    x['a'] = 3
    x['b'] = 5
    x['c'] = 8
    print(x)
    ##有序例
    import collections
    x = collections.OrderedDict() 
    x['a'] = 3
    x['b'] = 5
    x['c'] = 8
    print(x)
                               
#字典推导式
def func11():
    s = {x:x.strip() for x in ('  he  ', 'she    ', '    I')}
    print(s)
    for k, v in s.items():
        print(k, ':', v)

#13集合
def eg27():
    #赋值
    a={3,5}
    a.add(7)
    print(a)
    a_set=set(range(8,14))
    print(a_set)
    b_set=set([0,1,2,3,0,1,2,3,7,8])
    print(b_set)
    c_set = set() #空集合
    print(c_set)

def eg28():
    #删除
    a={1, 4, 2, 3}
    a.pop()
    print(a)
    a.pop()
    print(a)
    a.add(2)
    print(a)
    a.remove(3) #删除指定元素
    print(a)
    #a.pop(2) #pop()方法不接收参数

def eg29():
#操作
    a_set=set(range(8,14))
    print(a_set)
    b_set=set([0,1,2,3,0,1,2,3,7,8])
    print(a_set.union(b_set))
    print(a_set)
    print(b_set)
    print(a_set&b_set)
    print(a_set.intersection(b_set))
    print(a_set.difference(b_set))
    print(a_set.symmetric_difference(b_set))
    print(a_set^b_set)                               

#集合的推导式
def eg30():
    s = {x.strip() for x in ('  he  ', 'she    ', '    I')}
    print(s)

##集合应用
def func12():
    import random
    listRandom = [random.choice(range(20)) for i in range(10)]
    noRepeat = []
    for i in listRandom :
        if i not in noRepeat :
            noRepeat.append(i)
    print(len(listRandom))
    print(len(noRepeat))
    newSet = set(listRandom)
    print(listRandom)
    print(newSet)



    
                               
