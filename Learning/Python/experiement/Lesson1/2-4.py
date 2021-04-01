Python 3.9.2 (tags/v3.9.2:1a79785, Feb 19 2021, 13:44:55) [MSC v.1928 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> s1 = "programming"
>>> s2 = "language"
>>> s1[1]
'r'
>>> s1[:4]
'prog'
>>> s1[0]
'p'
>>> s1[0]+s2[1:3]
'pan'
>>> s1.capitalize()
'Programming'
>>> s1.capitalize() + '' + s2.upper()
'ProgrammingLANGUAGE'
>>> s1.count('r')+s1.find('r')+s1.rfind('r')
7
>>> s1.count('r')
2
>>> s1.find('r')
1
>>> s1.rfind('r')
4
>>> s1.rfind('m')
7
>>> s2.mfind('m')
Traceback (most recent call last):
  File "<pyshell#13>", line 1, in <module>
    s2.mfind('m')
AttributeError: 'str' object has no attribute 'mfind'
>>> s3 = s2.join("--")
>>> s3
'-language-'
>>> s4='-'.join(s2)
>>> s4
'l-a-n-g-u-a-g-e'
>>> L1 = s4.split()
>>> L1
['l-a-n-g-u-a-g-e']
>>> type(L1)
<class 'list'>
>>> 3 * (s2[:2]+'')
'lalala'
>>> 3 * (s2[:2])
'lalala'
>>> "Python"+s2.rjust(10)
'Python  language'
>>> 