# -*- coding:utf-8 -*-

class A(object):
       def __init__(self):
              self.__private()
              self.public()
       def __private(self):
              print('__private() method of A')
       def public(self):
              print('public() method of A')

class B(A):
       def __private(self):
              print('__private() method of B')
       def public(self):
              print('public() method of B')

class C(A):
       def __init__(self):
              self.__private()
              self.public()
       def __private(self):
              print('__private() method of C')
       def public(self):
              print('public() method of C')              

if __name__ =='__main__':
    b = B() #自动调用从基类A继承的构造函数
    c = C()
    print('===============')
    print('\n'.join(dir(b)))#查看对象b的成员
    print('===============')
    print('\n'.join(dir(c)))#查看对象b的成员
