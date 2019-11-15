#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
	unordered_map<uint8_t, uint8_t> reversedByteCache;
    uint8_t reverse_byte(uint8_t n) {
		auto found = reversedByteCache.find(n);
		if (found != reversedByteCache.end()) {
			return found->second;
		}
		uint8_t res = 0;
        for (int i = 0; i < 8; i++) {
            if (n & (1 << i)) {
				res += 1 << (7 - i);
            } 
        }
		reversedByteCache[n] = res;
        return res;
    }
public:
    uint32_t reverse_bits_cached(uint32_t n) {
        return 	reverse_byte(n & 0xff) << 24|
				reverse_byte((n >> 8)  & 0xff) << 16 |
				reverse_byte((n >> 16)  & 0xff) << 8 |
				reverse_byte((n >> 24)  & 0xff);
	}
    uint32_t reverse_bits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				res += 1 << (31 - i);
			} 
		}
        return res;
	}
    uint32_t reverse_bits_with_string(uint32_t n) {
        string str(32, '0');
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                str[i] = '1';
            } 
        }
        cout << str << endl;;
        return (uint32_t)stoul(str,nullptr, 2);
    }
};

int main() {
    Solution sol;
    cout << sol.reverse_bits_with_string(2) << endl;
    cout << sol.reverse_bits(2) << endl;
    cout << sol.reverse_bits_cached(2) << endl;
}

