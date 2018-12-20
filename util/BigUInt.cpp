#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

class BigUInt {
private:
    // Stores the reversed string for easier processing
    std::string s_; 
public:
    explicit BigUInt(std::string x) {    
        s_ = x;
        std::reverse(s_.begin(), s_.end());
    }
    std::string getReversedString() const {
        return s_;
    }
    std::string getString() const {
        std::string res = s_;
        std::reverse(res.begin(), res.end());
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const BigUInt& bi);
    friend BigUInt operator+(const BigUInt& lhs, const BigUInt& rhs);
    friend BigUInt operator*(const BigUInt& lhs, const BigUInt& rhs);
};

//TODO: Fix this so it works correctly with arguments outside the uint64_t range
//      The output should be fine for now for the other cases
//TODO: Improve performance
BigUInt operator*(const BigUInt& lhs, const BigUInt& rhs) {
    BigUInt res("0"); 
    std::string timesRhsStr = rhs.getString();
    uint64_t timesRhs = std::stoull(timesRhsStr);
    for (uint64_t i = 0; i < timesRhs; ++i) {
        res = res + lhs;
    }
    return res;
}

BigUInt operator+(const BigUInt& lhs, const BigUInt& rhs) {
    std::string strSmall;
    std::string strLarge;
    if (lhs.s_.length() < rhs.s_.length()) {
        strSmall = lhs.s_;
        strLarge = rhs.s_;
    } else {
        strSmall = rhs.s_;
        strLarge = lhs.s_;
    }
    std::string res = strLarge; 
    int carry = 0;
    // Run while both strings still have existing characters
    int i = 0;
    for (i = 0; i < strSmall.length(); ++i) {
        int sum = (strSmall[i] - '0') + (strLarge[i] - '0') + carry;
        carry = (sum > 9) ? 1 : 0;
        res[i] = std::to_string(sum % 10)[0];
    }
    // Run though the remaining characters if any
    for (; i < strLarge.length(); ++i) {
        int sum = (strLarge[i] - '0') + carry;
        carry = (sum > 9) ? 1 : 0;
        res[i] = std::to_string(sum % 10)[0];
    }
    std::reverse(res.begin(), res.end());
    if (carry) {
        res  = "1" + res;
    }
    return BigUInt(res);
}

std::ostream& operator<<(std::ostream& os, const BigUInt& bi) {
    for (int i = 0; i < bi.s_.length(); ++i) {
        os << bi.s_[bi.s_.length() - i - 1];
    }
    return os;
}

#include "BigUIntTests.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
