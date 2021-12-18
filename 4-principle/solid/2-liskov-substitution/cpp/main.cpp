// derived class object should be substitutable for the superclass object from which it is derived

#include <iostream>

using namespace std;

// violates LSP
class BaseArmor {
public:
    BaseArmor() {}
    void defendAttack() {
        cout << "defend physical attacks" << endl;
    } 
};

class ReboundArmor: public BaseArmor {
public:
    ReboundArmor() {}
    // void defendAttack() override { compile error, the superclass bevavior has changed
    void defendAttack() {
        cout << "defend physical attacks while rebounding attack to the enemy" << endl;
        // this modification makes defendAttack behavior changed
        // thus ReboundArmor.defendAttack cannot substitude BaseArmor.defendAttack
    }
};

// obeys LSP
// the superclass of IceArmor
// able to defend attacks
class Armor {
public:
    Armor() {}
    void defendAttack() {}
};

// derived class from Armor, the superclass of Antitoxin
// still be able to defend attacks
class IceArmor: public Armor {
public:
    IceArmor() {}
    void resistFire() {}
};

// derived class from IceArmor
// still be able to resist fire
class AntitoxinIceArmor: public IceArmor {
public:
    AntitoxinIceArmor() {}
    void resistToxin() {}
};

int main() {
    BaseArmor b;
    b.defendAttack();
    ReboundArmor r;
    r.defendAttack();
    return 0;
}
