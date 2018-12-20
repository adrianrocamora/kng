#include <iostream>
#include <thread>

using namespace std;

class Request {
public:
    Request(int id) : mId(id){ }
    void process() const {
        cout << "Processing request " << mId << endl;
    }
private:
    int mId;
};

int main() {
    Request req(100);
    thread t{&Request::process, &req};
    t.join();
}
