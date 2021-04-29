''' 6.2 在派生类中调用基类方法
    首先设计Person类，然后以Person为基类派生Teacher类，分别创建Person类和Teacher类的对象，
    并在派生类对象中调用基类方法。'''


class Person:
    def __init__(self, name='', age=20, sex='man'):
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
            print('name must be integer.')
            return
        self.__age = age

    def setSex(self, sex):
        if sex != 'man' and sex != 'woman':
            print('sex must be "man" or "woman"')
            return
        self.__sex = sex

    def show(self):
        print('Name', self.__name)
        print('Age', self.__age)
        print('Sex', self.__sex)


class Teacher(Person):  # 派生类
    def __init__(self, name="", age=30, sex='man', department='Computer'):
        super(Teacher, self).__init__(name, age, sex)
        # #or, use another method like below:
        # Person.__init__(self, name, age, sex)
        self.setDepartment(department)

    def setDepartment(self, department):
        if not isinstance(department, str):
            print('department must be a string.')
            return
        self.__department = department

    def show(self):
        # Person.show()
        super(Teacher, self).show()
        print('Department:', self.__department)


if __name__ == '__main__':
    zhangsan = Person('Zhang San', 19, 'man')
    zhangsan.show()
    lisi = Teacher('Li Si', 32, 'man', 'Math')
    lisi.show()
    lisi.setAge(40) # 派生类调用基类的方法
    lisi.show()

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
# class B(A):  # 注意，类B没有定义构造函数
#
#     def __private(self):
#         print('__private() method in B')
#
#     def public(self):
#         print('public() method in B')
#
#
# b = B()
# # __private() method in A
# # public() method in B
# print(dir(b))
#
#
# # ['_A__private', '_B__private', '__class__'...]
#
# class C(A):
#     def __init__(self):  # 显示定义构造函数
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
# # __private() method in C
# # public() method in C
# print(dir(c))
# # ['_A__private', '_C__private', '__class__', ...]
