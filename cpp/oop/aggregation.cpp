#include <string>

class Teacher {
private:
    std::string strName_;
public:
    Teacher(std::string strName): strName_(strName) {}
    std::string getName() { return strName_;}
};

class Department {
private:
    Teacher *teacher_;  // This dept holds only one teacher
public:
    Department(Teacher *teacher=nullptr) : teacher_(teacher) {}
};

int main() {
    Teacher *teacher = new Teacher("Bob");
    {
        Department dept(teacher);
    }   // dept goes out of scope
    delete teacher; // Teacher still exists because dept did not destroy it
}
