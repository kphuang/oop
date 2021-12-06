#include <iostream>

using namespace std;

// Single inheritance
class Base {
public:
    Base() {
        cout << "Base object constructed" << endl;
    }
    void BaseMethod() {
        cout << "Base method called" << endl;
    }
};

class Derived: public Base {
public:
    Derived() {
        cout << "Derived object constructed" << endl;
    }
    void ExtendedMethod() {
        cout << "Extended method called" << endl;
    }
};

// Multiple inheritance
class Father {
public:
    Father() {
        cout << "Father object constructed" << endl;
    }
    void doExercise() {
        cout << "Do exercise" << endl;
    }
};

class Mother {
public:
    Mother() {
        cout << "Mother object constructed" << endl;
    }
    void doReading() {
        cout << "Do reading" << endl;
    }
};

class Child: public Father, public Mother {
public:
    Child() {
        cout << "Child object constructed" << endl;
    }
    void doExperiment() {
        cout << "Do experiment" << endl;
    }
};

int main() {
    Base b;
    Derived d;
    d.BaseMethod();
    d.ExtendedMethod();
    
    Child c;
    c.doExercise();
    c.doReading();
    c.doExperiment();

    return 0;
}
