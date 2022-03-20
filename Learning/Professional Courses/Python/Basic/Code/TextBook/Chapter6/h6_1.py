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


class Student(Person):
    def __init__(self, name="", age=18, sex='man', major='Computer Science'):
        super(Student, self).__init__(name, age, sex)
        self.setMajor(major)

    def setMajor(self, major):
        if not isinstance(major, str):
            print('Major must be a string.')
            return
        self.__major = major

    def show(self):
        Person.show(self)
        print('Major', self.__major)


if __name__ == '__main__':
    w = Student()
    w.show()
    w = Student('wendy', 20, 'woman', 'Data Analyse')
    w.show()
''' 输出结果
Name 
Age 18
Sex man
Major Computer Science
Name wendy
Age 20
Sex woman
Major Data Analyse
'''