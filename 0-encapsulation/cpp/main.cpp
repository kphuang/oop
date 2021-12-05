#include <iostream>

using namespace std;

class Without {
public:
    Without() {
        age = 0;
    }
    int age;
};

class With {
    int age;
public:
    With() {
        age = 0;
    }

    void setAge(int v) {
        if (v < 0 || v > 150) {
            cout << "Impossible for humans" << endl;
            return;
        }
        age = v;
    }

    int showAge() {
        return age;
    }
};

int main() {
    Without o;
    With w;

    // losing control of age
    o.age = 200; 
    o.age = -200;
    cout << o.age << endl;

    // w.age = 200; not able to compile
    w.setAge(160); // 
    // cout << w.age << endl; not able to compile
    cout << w.showAge() << endl;
}
