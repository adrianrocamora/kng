#include <iostream>
#include <memory>

using namespace std;

class FileSystem {
private:
    FileSystem() {}
    static unique_ptr<FileSystem> instance_;
public:
	// Returning a reference makes sense for a singleton
	// and simplifies smart pointer usage
    static FileSystem& instance() {
        // Lazy initialize
        if (!instance_) {
            //instance_ = make_unique<FileSystem>();
			// make_unique gives us some issues do to 
			// access rules, so just create it with new
            instance_ = unique_ptr<FileSystem>(new FileSystem());
        }
        return *instance_;
    }
	void sayHello() {
		cout << "Hello" << endl;
	}
    virtual ~FileSystem() {}
};

// Allocate and initialize static data members
// The pointer is being allocated, not the object
unique_ptr<FileSystem> FileSystem::instance_ = nullptr;

int main() {
	FileSystem::instance().sayHello();
	FileSystem::instance().sayHello();
}
