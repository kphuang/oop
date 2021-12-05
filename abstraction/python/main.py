class Shape():
    def __init__(self):
        print("A shape object is created")

    def get_area(self) -> float:
        return 0

class Circle(Shape):
    def __init__(self, radius):
        self.__radius = radius
        print("A circle object is created")

    def get_area(self) -> float:
        return self.__radius ** 2 * 3.1415926

class Triangle(Shape):
    def __init__(self, base, height):
        self.__base = base
        self.__height = height
        print("A triangle object is created")

    def get_area(self) -> float:
        return self.__base * self.__height / 2 

def main():
    shapes = []
    shapes.append(Circle(3))
    shapes.append(Triangle(3, 4))

    # suppose we just need to get areas of shapes without knowing what shares they are
    for s in shapes:
        print(s.get_area())

if __name__ == '__main__':
    main()
