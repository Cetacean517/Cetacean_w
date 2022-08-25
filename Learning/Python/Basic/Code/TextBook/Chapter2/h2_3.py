import random


def generateThousand():
    a = [random.randint(0, 101) for x in range(1000)]
    return sorted({x: a.count(x) for x in a}.items(), key=lambda x: x[0])


print(generateThousand())
