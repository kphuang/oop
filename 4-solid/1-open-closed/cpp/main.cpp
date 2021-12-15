// open to extension, closed to modification

// violates OCP
class ArmorAllInOne {
public:
    ArmorAllInOne() {}
    void defendAttack() {}
    void resistFire() {} // added later on
    void resistToxin() {} // added after resistFire is added
};

// obeys OCP
// will not be modified after implemented
class Armor {
public:
    Armor() {}
    void defendAttack() {}
};

// extended from Armor
class IceArmor: public Armor {
public:
    IceArmor() {}
    void resistFire() {}
};

// extended from IceArmor
class AntitoxinIceArmor {
public:
    AntitoxinIceArmor() {}
    void resistToxin() {}
};

int main() {
    return 0;
}
