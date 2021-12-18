// there is only one reason to change a class

// violates SRP
// there are more than one reason to modify the class
class Multifunctional {
public:
    Multifunctional() {}
    void print() {}
    void scan() {}
    void fax() {}
};

// obeys SRP
// there is only one reason to modify each of the three classes
class Printer {
public:
    Printer() {}
    void print() {}
};

class Scanner {
public:
    Scanner() {}
    void scan() {}
};

class FaxMachine {
public:
    FaxMachine() {}
    void fax() {}
};

int main() {
    return 0;
}
