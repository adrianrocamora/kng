#include <iostream>

using namespace std;

class FileSystem {
private:
    FileSystem() {}
    static FileSystem* instance_;
public:
    static FileSystem& instance() {
        // Lazy initialize
        if (!instance_) {
            instance_ = new FileSystem();
        }
        return *instance_;
    }
	void sayHello() {
		cout << "Hello" << endl;
	}
    ~FileSystem() { 
		delete instance_;
		instance_ = nullptr;
	}
};

// Allocate and initialize static data members
// The pointer is being allocated, not the object
FileSystem* FileSystem::instance_ = nullptr;

int main() {
	FileSystem::instance().sayHello();
	FileSystem::instance().sayHello();
}
