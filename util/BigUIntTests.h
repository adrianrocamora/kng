#pragma once
#include <gtest/gtest.h>

// Too slow!!! Python solves this super fast
//TEST(BigUIntTest, prod_very_large) {
    //BigUInt a0("8446744073709551615");
    //BigUInt b0("9313515121523461293");
    //std::ostringstream is;
    //BigUInt prod = a0 * b0;
    //is << prod;
    //ASSERT_EQ("78668878658132591102896559609838138195", is.str());
//}

TEST(BigUIntTest, prod_beyond_uint64_t) {
    BigUInt a0("8446744073709551615");
    BigUInt b0("931000");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("7863918732623592553565000", is.str());
}

TEST(BigUIntTest, prod_8_17) {
    BigUInt a0("8");
    BigUInt b0("17");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("136", is.str());
}
TEST(BigUIntTest, prod_128_0) {
    BigUInt a0("128");
    BigUInt b0("0");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("0", is.str());
}

TEST(BigUIntTest, prod_8_0) {
    BigUInt a0("8");
    BigUInt b0("0");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("0", is.str());
}

TEST(BigUIntTest, prod_0_128) {
    BigUInt a0("0");
    BigUInt b0("128");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("0", is.str());
}

TEST(BigUIntTest, prod_0_8) {
    BigUInt a0("0");
    BigUInt b0("8");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("0", is.str());
}

TEST(BigUIntTest, prod_0_0) {
    BigUInt a0("0");
    BigUInt b0("0");
    std::ostringstream is;
    BigUInt prod = a0 * b0;
    is << prod;
    ASSERT_EQ("0", is.str());
}

TEST(BigUIntTest, sum_beyond_uint64_t) {
    BigUInt a0("999999999999999999");
    BigUInt b0("1234123411234123412351512342561512");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("1234123411234124412351512342561511", is.str());
}

TEST(BigUIntTest, sum_3_999) {
    BigUInt a0("3");
    BigUInt b0("999");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("1002", is.str());
}

TEST(BigUIntTest, sum_789_999) {
    BigUInt a0("789");
    BigUInt b0("999");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("1788", is.str());
}

TEST(BigUIntTest, sum_7_4) {
    BigUInt a0("7");
    BigUInt b0("4");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("11", is.str());
}

TEST(BigUIntTest, sum_0_0) {
    BigUInt a0("0");
    BigUInt b0("0");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("0", is.str());
}

TEST(BigUIntTest, sum_4_5) {
    BigUInt a0("4");
    BigUInt b0("5");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("9", is.str());
}

TEST(BigUIntTest, sum_5_4) {
    BigUInt a0("4");
    BigUInt b0("5");
    std::ostringstream is;
    BigUInt sum = a0 + b0;
    is << sum;
    ASSERT_EQ("9", is.str());
}

TEST(BigUIntTest, Ostream1) {
    BigUInt is1("1");
    std::ostringstream is;
    is << is1;
    ASSERT_EQ("1", is.str());
}

TEST(BigUIntTest, Ostream12) {
    BigUInt is12("12");
    std::ostringstream is;
    is << is12;
    ASSERT_EQ("12", is.str());
}

TEST(BigUIntTest, Ostream123) {
    BigUInt is123("123");
    std::ostringstream is;
    is << is123;
    ASSERT_EQ("123", is.str());
}

TEST(BigUIntTest, InternalStr1) {
    BigUInt is1("1");
    ASSERT_EQ("1", is1.getReversedString());
}

TEST(BigUIntTest, InternalString21) {
    BigUInt is12("12");
    ASSERT_EQ("21", is12.getReversedString());
}

TEST(BigUIntTest, InternalString321) {
    BigUInt is123("123");
    ASSERT_EQ("321", is123.getReversedString());
}

