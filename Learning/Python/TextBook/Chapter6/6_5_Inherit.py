''' 6.2 在派生类中调用基类方法
    首先设计Person类，然后以Person为基类派生Teacher类，分别创建Person类和Teacher类的对象，
    并在派生类对象中调用基类方法。'''

# 基类
# 基类必须继承于object
# 否则再派生类中无法使用super调用基类

# class Person(object):
#     def __init__(self, name='', age=20, sex='man'):
#         self.setName(name)
#         self.setAge(age)
#         self.setSex(sex)
#
#     def setName(self, name):
#         if not isinstance(name, str):
#             print('name must be string.')
#             return
#         self.__name = name
#
#     def setAge(self, age):
#         if not isinstance(age, int):
#             print('name must be integer.')
#             return
#         self.__age = age
#
#     def setSex(self, sex):
#         if sex != 'man' and sex != 'woman':
#             print('sex must be "man" or "woman"')
#             return
#         self.__sex = sex
#
#     def show(self):
#         print('Name', self.__name)
#         print('Age', self.__age)
#         print('Sex', self.__sex)
#
#
# class Teacher(Person):  # 派生类
#     def __init__(self, name="", age=30, sex='man', department='Computer'):
#         # 调用基类构造方法初始化基类的私有成员，注意使用格式
#         # super(Teacher,self)返回的是基类的指针，推荐使用super()方法调用基类构造。
#         super(Teacher, self).__init__(name, age, sex)
#         # #or, use another method like below:
#         # Person.__init__(self, name, age, sex)
#         self.setDepartment(department)
#
#     def setDepartment(self, department):
#         if not isinstance(department, str):
#             print('department must be a string.')
#             return
#         self.__department = department
#
#     def show(self):
#         # Person.show()
#         super(Teacher, self).show()
#         print('Department:', self.__department)
#
#
# if __name__ == '__main__':
#     zhangsan = Person('Zhang San', 19, 'man')
#     zhangsan.show()
#     lisi = Teacher('Li Si', 32, 'man', 'Math')
#     lisi.show()
#     lisi.setAge(40) # 派生类调用基类的方法
#     lisi.show()


# class A(object):
#     def __init__(self):
#         self.__private()
#         self.public()
#
#     def __private(self):
#         print('__private() method in A')
#
#     def public(self):
#         print('public() method in A')
#
#
# class B(A):  # 注意，类B没有定义构造函数； 没有构造的函数调用基类的构造函数
#
#     def __private(self):
#         print('__private() method in B')
#
#     def public(self):
#         print('public() method in B')
#
#
# b = B()
# # __private() method in A # 调用了A类的私有函数的构造函数，不能访问派生类B的私有函数
# # public() method in B    # 调用了A类的共有成员的构造函数
# print(dir(b))
#
#
# # ['_A__private', '_B__private', '__class__'...]
#
# class C(A):
#     def __init__(self):  # 显示定义构造函数，构造被覆写后调用对象的构造函数
#         self.__private()
#         self.public()
#
#     def __private(self):
#         print('__private() method in C')
#
#     def public(self):
#         print('public() method in C')
#
#
# c = C()
# # __private() method in C   # 调用了C类的构造方法，由于被覆写
# # public() method in C
# print(dir(c))
# # ['_A__private', '_C__private', '__class__', ...]
'''继承 输出3'''


class D:
    attr = 3


class B(D):
    pass


class E:
    attr = 2


class C(E):
    attr = 1


class A(B, C):
    pass


X = A()
print(X.attr)

'''继承输出1 python 3.0 可能再python2.0中不一样。'''


class D:
    attr = 3


class B(D):
    pass


class E:
    attr = 2


class C(D):
    attr = 1


class G(D):
    print('get G')
    attr = 5


class A(B, C, G):
    pass


X = A()
print(X.attr)
