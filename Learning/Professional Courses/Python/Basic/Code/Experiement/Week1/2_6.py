Python 3.9.2 (tags/v3.9.2:1a79785, Feb 19 2021, 13:44:55) [MSC v.1928 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> import math
>>> math.log(10)
2.302585092994046
>>> math.log2(2)
1.0
>>> math.log(10,10)
1.0
>>> math.sqrt(9)
3.0
>>> math.exp(3)
20.085536923187668
>>> math.ceil(3.3)
4
>>> math.floor(3.4)
3
>>> 

>>> import random
>>> a = [random.randint(1,100) for i in range(10)]
>>> a
[47, 34, 54, 44, 12, 34, 50, 79, 16, 93]
>>> print(max(a),min(a),sum(a))
93 12 463
>>> sum(a) * 1.0 / len(a)
46.3
>>> sum(a) / len(a)
46.3
>>> 