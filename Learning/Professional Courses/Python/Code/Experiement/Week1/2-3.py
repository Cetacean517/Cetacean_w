Python 3.9.2 (tags/v3.9.2:1a79785, Feb 19 2021, 13:44:55) [MSC v.1928 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> 23 + 3
26
>>> 23 > 3
True
>>> '23' + '3'
'233'
>>> 23/3
7.666666666666667
>>> 23//3
7
>>> 23 % 3
2
>>> 23 ** 3
12167
>>> 23 + 24.5
47.5
>>> 23 + '3'
Traceback (most recent call last):
  File "<pyshell#8>", line 1, in <module>
    23 + '3'
TypeError: unsupported operand type(s) for +: 'int' and 'str'
>>> 23 + int('3')
26
>>> 'hello' + str("123")
'hello123'
>>> int(23/3)
7
>>> round(23/3,2)
7.67
>>> round(23/3)
8
>>> 0 < 23 < 100
True