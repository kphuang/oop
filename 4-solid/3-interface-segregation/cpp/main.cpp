// the client should not be forced to depend on methods or functions it does not use

// violates ISP
class IMultifunctional {
public:
    IMultifunctional() {}
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

class ScannerFax0: public IMultifunctional {
public:
    ScannerFax0() {}
    void print() override {} // not used nor implemented
    void scan() override {}
    void fax() override {}
};

// obyes ISP
// this interface will not be used
class IPrinter {
public:
    virtual void print() = 0;
};

// this interface will be used
class IScanner {
public:
    virtual void scan() = 0;
};

class ScannerModule: public IScanner {
public:
    void scan() override {}
};

// this interface will be used
class IFaxMachine {
public:
    virtual void fax() = 0;
};

class FaxModule: public IFaxMachine {
public:
    void fax() override {}
};

class ScannerFax1 {
    IScanner *_s;
    IFaxMachine *_f;
public:
    ScannerFax1(IScanner *s, IFaxMachine *f): _s(s), _f(f) {}
    void scan() {_s->scan();}
    void fax() {_f->fax();}
};

int main() {
    ScannerFax0 sf0;
    ScannerFax1 sf1{new ScannerModule{}, new FaxModule{}};

    sf0.print(); // prints not implemented, which should not be able to work
    sf0.scan();
    sf0.fax();

    // sf1.print(); // compile error
    sf1.scan();
    sf1.fax();

    return 0;
}
