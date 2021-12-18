#include <vector>

using namespace std;

// the interface
class IProduct {};
class ICreator {
public:
    virtual IProduct *create() = 0;
};

// the product
class Table: public IProduct {};

// the creator which creates product
class TableFactory: public ICreator {
public:
    TableFactory() {}
    IProduct *create() {
        return new Table{};
    }
};

// the class which uses factory method pattern
class Manufacturer {
    ICreator *_c;
    vector<IProduct *> _p;
public:
    Manufacturer(ICreator *c): _c(c) {}
    void create(unsigned int q) {
        for (int i = 0; i < q; i++)
            _p.emplace_back(_c->create());
    }
}; 

int main() {
    Manufacturer m{new TableFactory{}};
    m.create(10);
    return 0;
}
