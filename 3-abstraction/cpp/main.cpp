// objects use interfaces instead of concrete implementations to interact
#include <iostream>
#include <unordered_map>
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
    unordered_map<string, Transportation *> m; // mapping name to transportation system
    m["bus"] = new BusService{new Bus{}};
    m["logistics"] = new Logistics{new Ship{}};

    m["bus"]->transit();
    m["logistics"]->transit();

    return 0;
}
