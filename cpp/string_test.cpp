#include <iostream>
#include <string>

using namespace std;

int main() {
    const char myStr[] = "This is a test";
    std::cout << &myStr[0] << std::endl;
    std::cout << strlen("This is a test") << std::endl;

    int arr[] = {104,101,108,108,111};
    std::cout << &arr[0] << std::endl;

    char arr2[] = {104,101,108,108,111,0};
    std::cout << &arr2[0] << std::endl;

    // OUTPUT: 
    //This is a test
    //14
    //0x7fff54acfaa0
    //helloV
}
