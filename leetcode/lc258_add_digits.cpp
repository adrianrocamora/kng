#include <iostream>
#include <string>

int addDigitsWithString(int num) {
    while (num > 9 ) {
        std::string strNum = std::to_string(num);
        int sum = 0; 
        for (int i = 0; i < strNum.length(); i++) {
            sum += std::stoi(std::string(1,strNum.at(i)));
        }
        num = sum;
    }
    return num;
}

int addDigitsWithString2(int num) {
    while (num > 9 ) {
        std::string strNum = std::to_string(num);
        int sum = 0; 
        for (int i = 0; i < strNum.length(); i++) {
            sum += strNum.at(i) - '0';;
        }
        num = sum;
    }
    return num;
}

int addDigits(int intNum) {
    long num = (long)intNum;;
    while (num / 10 > 0) {
        long sum = 0;
        long mod = 1;
        while (num / mod > 0) {
            sum += (num % (mod*10)) / mod;
            mod *= 10;
        }
        num = sum;
    }
    return (int)num;
}

int addDigitsFaster(int num) {
    return num - 9 *((num - 1) / 9);
}

int addDigitsFaster2(int num) {
    return 1 + (num - 1) % 9;
}

int main() {
    std::cout << "38: " << addDigits(38) << " == 2" << std::endl;
    std::cout << "38: " << addDigitsFaster(38) << " == 2" << std::endl;
    std::cout << "38: " << addDigitsFaster2(38) << " == 2" << std::endl;
    std::cout << "38: " << addDigitsWithString(38) << " == 2" << std::endl;
    std::cout << "38: " << addDigitsWithString2(38) << " == 2" << std::endl;
    std::cout << "2032610959: " << addDigits(2032610959) << " == 1" << std::endl;
    std::cout << "2032610959: " << addDigitsFaster(2032610959) << " == 1" << std::endl;
    std::cout << "2032610959: " << addDigitsFaster2(2032610959) << " == 1" << std::endl;
    std::cout << "2032610959: " << addDigitsWithString(2032610959) << " == 1" << std::endl;
    std::cout << "2032610959: " << addDigitsWithString2(2032610959) << " == 1" << std::endl;
}
