// derived class object should be substitutable for the superclass object from which it is derived

// violates LSP
class BaseArmor {
public:
    BaseArmor() {}
    void defendAttack() {
        // defend physical attacks
    } 
};

class ReboundArmor {
public:
    ReboundArmor() {}
    void defendAttack() override {
        // defend physical attacks while rebounding attack to the enemy
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
class AntitoxinIceArmor {
public:
    AntitoxinIceArmor() {}
    void resistToxin() {}
};

int main() {
    return 0;
}
