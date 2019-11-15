#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    bool    reverseByteCacheSet[256]
    uint8_t reverseByteCache[256];
public:
    uint8_t reverseByte(uint8_t x) {
        for (int i = 0; i < 8; i++) {
            uint8_t res = 0;
            uint8_t currBit = 1 << i;
            uint8_t reverseBit = 1 << (8 - i - 1);
            if (x & currBit) {
                res += reverseBit;
            } 
            return res;
        }
    };
    uint32_t reverseBitsBitwiseCached(uint32_t n) {
        return  reverseByte(n & 0xff) |
                reverseByte((n >> 8) & 0xff) << 8 |
                reverseByte((n >> 16) & 0xff) << 16 |
                reverseByte((n >> 24) & 0xff) << 24;
    }
    uint32_t reverseBitsBitwise(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t currBit = 1 << i;
            uint32_t reverseBit = 1 << (32 - i - 1);
            if (n & currBit ) {
                res += reverseBit;
            } 
        }
        return res;
    }
    
    uint32_t reverseBitsUsingString(uint32_t n) {
        string str(32, '0');
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                str[i] = '1';
            } 
        }
        return (uint32_t)stoul(str,nullptr, 2);
    }
};

int main() {
    Solution sol;
    cout << sol.reverseBitsUsingString(2) << endl;
    cout << sol.reverseBitsBitwise(2) << endl;
    cout << sol.reverseBitsBitwiseCached(2) << endl;
}
