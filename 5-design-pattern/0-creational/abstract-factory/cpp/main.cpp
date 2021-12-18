#include <vector>

using namespace std;

// the interface
class ITable {};
class FancyTable: public ITable {};
class VintageTable: public ITable {};

class IChair {};
class FancyChair: public IChair {};
class VintageChair: public IChair {};

class IFactory {
public:
    virtual ITable *createTable() = 0;
    virtual IChair *createChair() = 0;
};

class FancyFactory: public IFactory {
public:
    FancyFactory() {}
    ITable *createTable() {
        return new FancyTable{};
    }
    IChair *createChair() {
        return new FancyChair{};
    }
};

class VintageFactory: public IFactory {
public:
    VintageFactory() {}
    ITable *createTable() {
        return new VintageTable{};
    }
    IChair *createChair() {
        return new VintageChair{};
    }
};

// the class which uses factory method pattern
class Manufacturer {
    IFactory *_f;
    vector<ITable *> _t;
    vector<IChair *> _c;
public:
    Manufacturer(IFactory *f): _f(f) {}
    void createSet(unsigned int q) {
        for (int i = 0; i < q; i++) {
            _t.emplace_back(_f->createTable());
            _c.emplace_back(_f->createChair());
        }
    }
}; 

int main() {
    Manufacturer m0{new FancyFactory{}};
    m0.createSet(10);
    Manufacturer m1{new VintageFactory{}};
    m1.createSet(20);
    return 0;
}
