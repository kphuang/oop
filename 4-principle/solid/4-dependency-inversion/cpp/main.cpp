// 1. higher level module should not depend on lower level module, both should depend on abstract interfaces.
// 2. abstract interface should not depend on concrete implementaion. concrete implementation should depend on abstract interface.

// violates DIP
class MySQL0 {};
class NetworkMonitor0 {};
class NetPerfService0 {
    MySQL0 mySQL;
    NetworkMonitor0 networkMonitor;
public:
    NetPerfService0() {}
    void start() {}
    void check() {}
    void stop() {}
};

// obeys DIP
class IDatabase {
public:
    virtual void connect() = 0;
    virtual void crud() = 0;
    virtual void disconnect() = 0;
};

class MySQL: public IDatabase {
public:
    MySQL() {}
    void connect() override {}
    void crud() override {}
    void disconnect() override {}
};

class PostgreSQL: public IDatabase {
public:
    PostgreSQL() {}
    void connect() override {}
    void crud() override {}
    void disconnect() override {}
};

class IMonitor {
public:
    virtual void start() = 0;
    virtual void getData() = 0;
    virtual void stop() = 0;
};

class NetworkMonitor: public IMonitor {
public:
    NetworkMonitor() {}
    void start() override {}
    void getData() override {}
    void stop() override {}
};

class MemoryMonitor: public IMonitor {
public:
    MemoryMonitor() {}
    void start() override {}
    void getData() override {}
    void stop() override {}
};

class IService {
public:
    virtual void start() = 0;
    virtual void check() = 0;
    virtual void stop() = 0;
    virtual void setDB(IDatabase *db) = 0;
    virtual void setMonitor(IMonitor *m) = 0;
};

class PerfService: public IService {
    IDatabase *_db;
    IMonitor *_m;
public:
    PerfService(IDatabase *db, IMonitor *m): _db(db), _m(m) {}
    void start() override {
        _db->connect();
        _m->start();
    }
    void check() override {
        _m->getData();
        _db->crud();
    }
    void stop() override {
        _m->stop();
        _db->disconnect();
    }
    void setDB(IDatabase *db) override {
        _db = db;
    }
    void setMonitor(IMonitor *m) override {
        _m = m;
    }
};

int main() {
    IService *s = new PerfService{new MySQL{}, new NetworkMonitor{}};
    s->start();
    s->check();
    s->stop();
    s->setDB(new PostgreSQL{});
    s->start();
    s->check();
    s->stop();
    s->setMonitor(new MemoryMonitor{});
    return 0;
}
