#include <vector>

using namespace std;

// the product
class IProduct {};
class Table: public IProduct {};

// the creator which creates product
class ICreator {
public:
    virtual IProduct *createProduct() = 0;
};
class TableFactory: public ICreator {
public:
    TableFactory() {}
    IProduct *createProduct() {
        return new Table{};
    }
};

// the class which uses factory method pattern
class Manufacturer {
    ICreator *_c;
    vector<IProduct *> _p;
public:
    Manufacturer(ICreator *c): _c(c) {}
    void createProduct(unsigned int q) {
        for (int i = 0; i < q; i++)
            _p.emplace_back(_c->createProduct());
    }
}; 

int main() {
    Manufacturer m{new TableFactory{}};
    m.createProduct(10);
    return 0;
}
