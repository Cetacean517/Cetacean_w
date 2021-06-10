# -*- coding:utf-8 -*-

import types
#基类
#基类必须继承于object
#否则在派生类中将无法使用super()函数
class Person(object): 
    def __init__(self, name = '', age = 30, sex = 'Male'):
        self.setName(name)
        self.setAge(age)
        self.setSex(sex)
    def setName(self, name):
        if not isinstance(name, str):
            print('name must be string.')
            return
        self.__name = name
    def setAge(self, age):
        if not isinstance(age, int):
            print('age must be integer.')
            return
        self.__age = age
    def setSex(self, sex):
        if sex != 'Male' and sex != 'Female':
            print('sex must be "Male" or "Female"')
            return
        self.__sex = sex
    def show(self):
        print(self.__name)
        print(self.__age)
        print(self.__sex)

#派生类
class Teacher(Person):
    def __init__(self, name='', age = 30, sex = 'Male', department = 'Computer'):
        #调用基类构造方法初始化基类的私有数据成员
        super(Teacher, self).__init__(name, age, sex) 
        #Person.__init__(self, name, age, sex) #初始化基类的私有数据成员
        self.setDepartment(department) #初始化派生类的数据成员

    def setDepartment(self, department):
        if not isinstance(department, str):
            print('department must be a string.')
            return
        self.__department = department

    def show(self):
        super(Teacher, self).show()
        print(self.__department)

if __name__ =='__main__':
    zhangsan = Person('Zhang San', 39, 'Male')
    zhangsan.show()
    lisi = Teacher('Li Si', 32, 'Male', 'CS')
    lisi.show()
    lisi.setAge(40) #调用继承的方法修改年龄
    lisi.show()


