class Base():
    def __init__(self):
        print("Base class is created")

    def base_method(self):
        print("Base method")

class Derived(Base):
    def __init__(self):
        print("Derived class is created")

    def extended_method(self):
        print("Extended method")

def main():
   d = Derived()
   d.base_method()
   d.extended_method()

if __name__ == "__main__":
    main()
