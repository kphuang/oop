// aka principle of least knowledge

// violates law of demeter
class Motor {
public:
    Motor() {}
    void start() {}
    void spin() {}
    void stop() {}
};
class WashingMachine0 {
public:
    Motor *_m;
    WashingMachine0(Motor *m): _m(m) {}
};
class User0 {
    WashingMachine0 *_w;
public:
    User0(WashingMachine0 *w): _w(w) {}
    // user does not need to know the detail how a washing machine works
    void doLaundry() {
        _w->_m->start();
        _w->_m->spin();
        _w->_m->stop();
    }
};

// obeys law of demeter
class WashingMachine1 {
    Motor *_m;
public:
    WashingMachine1(Motor *m): _m(m) {}
    void wash() {
        _m->start();
        _m->spin();
        _m->stop();
    }
};

class User1 {
    WashingMachine1 *_w;
public:
    // washing machine provides least function(knowledge) wash to users
    User1(WashingMachine1 *w): _w(w) {}
    void doLaundry() {
        _w->wash();        
    }
};

int main() {
    return 0;
}
