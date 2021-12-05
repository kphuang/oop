# loose control of object attributes
class Without:
    def __init__(self):
        self.age = 0
        print("Without object is created")

# get control of object attributes
class With:
    def __init__(self):
        self.__age = 0
        print("With object is created")

    def set_age(self, v):
        if v < 0 or v > 150:
            print("Input value {} is impossible for human".format(v))
            return
        self.__age = v

    def get_age(self) -> int:
        return self.__age

def main():
    wo = Without()
    print(wo.age)
    wo.age = -100
    print(wo.age)
    ww = With()
    """
    print(ww.__age)

    Traceback (most recent call last):
      File "D:\workspace\oop\encapsulation\python\main.py", line 16, in <module>
        main()
      File "D:\workspace\oop\encapsulation\python\main.py", line 13, in main
        print(ww.__age)
    AttributeError: 'With' object has no attribute '__age'
    """
    ww.set_age(160)
    print(ww.get_age())
    ww.set_age(40)
    print(ww.get_age())

if __name__ == '__main__':
    main()
