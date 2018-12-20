#include <functional>
#include <iostream>
#include <string>
#include <vector>

class AddressBook {
public:
    AddressBook(std::vector<std::string> v) : addresses_(v) {}
    std::vector<std::string> findMatchingAddresses(std::function<bool (const std::string&)> func) {
        std::vector<std::string> res;
        for (auto it = addresses_.begin(), end = addresses_.end(); it != end; ++it) {
            if (func(*it)) {
                res.push_back(*it);
            }
        }
        return res;
    }
private:
    std::vector<std::string> addresses_;
};

int main() {
    AddressBook addressbook({"John Doe", "Jane Dane", "Nick Tesla"});
    std::vector<std::string> matches = addressbook.findMatchingAddresses([](const std::string& a) {
        return a[0] == 'J'; // Names starting with 'J'
    });
    for (auto &s : matches) {
        std::cout << s << std::endl;
    }
}
