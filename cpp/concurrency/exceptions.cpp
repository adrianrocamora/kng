#include <iostream>
#include <thread>
using namespace std;

void doSomeWork() {
    for (int i = 0; i < 5; ++i) {
        cout << i << endl;
    }
    cout << "Thread throws error" << endl;
    throw runtime_error("Exception from thread");
}

void threadFunc(exception_ptr& err) {
    try {
        doSomeWork();
    } catch (...) {
        cout << "Thread caught exception" << endl;
        err = current_exception();
    }
}

void doWorkInThread() {
    exception_ptr error;
    thread t{ threadFunc, ref(error) };
    t.join();
    if (error) {
        cout << "Main thread received exception, rethrowing" << endl;
        rethrow_exception(error);
    } else {
        cout << "Main thread did not receive any exceptions" << endl;
    }
}

int main() {
    try {
        doWorkInThread();
    } catch (const exception& e) {
        cout << "Main function caught: '" << e.what() << "'" << endl;
    }
}

