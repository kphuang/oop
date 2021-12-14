// using interface instead of concrete implementation to communicate
#include <iostream>
#include <vector>
using namespace std;

// an interface 
class Vehicle { 
public:
    virtual void transit() = 0;
};

// concrete implementations
class Bus: public Vehicle { 
public:
    Bus() {}
    void transit() override {}
};

class Ship: public Vehicle {
public:
    Ship() {}
    void transit() override {}
};

// another interface
class Transportation {
    Vehicle *_v;
public:
    Transportation(Vehicle *v): _v(v) {}
    void transit() {
        _v->transit();
    }
    void setVehicle(Vehicle *v) {
        if (!v)
            return;
        _v = v;
    }
};

// another concrete implementations
// For human
class BusService: public Transportation {
public:
    BusService(Vehicle *v): Transportation(v) {}
};

// For goods
class Logistics: public Transportation {
public:
    Logistics(Vehicle *v): Transportation(v) {}
};

int main() {
    vector<Transportation *> t; // interfaces we can use
    t.emplace_back(new BusService{new Bus{}});
    t.emplace_back(new Logistics{new Ship{}});

    t[0]->transit();
    t[1]->transit();

    return 0;
}
