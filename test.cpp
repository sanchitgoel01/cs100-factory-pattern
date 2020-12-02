#include "gtest/gtest.h"

#include <random>

#include "op.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "base.hpp"
#include "BaseFactory.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(OpTestAdd, AddAddAddAdd) {
    char* test_val[2]; 
    test_val[0] = "./calculator"; 
    test_val[1] = "5+4+3+2+1";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(15, test->evaluate());
}

TEST(OpTestAdd, AddSubMultDiv) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "5+6-1*2/4";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(5, test->evaluate());
}

TEST(OpTestAdd, AddMultDivSub) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "4+1*4/10-1";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(1, test->evaluate());
}

TEST(OpTestAdd, AddDivSubMult) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2+4/3-0*8";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(16, test->evaluate());
}

TEST(OpTestSub, SubSubSubSub) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "20-4-3-2-1";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(10, test->evaluate());
}

TEST(OpTestSub, SubAddMultDiv) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "30-10+5*4/2";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(50, test->evaluate());
}

TEST(OpTestSub, SubMultDivAdd) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "30-15*3/9+2";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(7, test->evaluate());
}

TEST(OpTestSub, SubDivAddMult) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "8-2/3+4*4";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(24, test->evaluate());
}

TEST(OpTestMult, MultMultMultMult) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "1*2*3*4*5";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(120, test->evaluate());
}

TEST(OpTestMult, MultAddSubDiv) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2*3+4-2/4";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(2, test->evaluate());
}

TEST(OpTestMult, MultSubDivAdd) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "3*3-1/4+6";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(8, test->evaluate());
}

TEST(OpTestMult, MultDivAddSub) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2+6/4+4-2";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(4, test->evaluate());
}

TEST(OpTestDiv, DivDivDivDiv) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "36/2/3/2/1";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(3, test->evaluate());
}

TEST(OpTestDiv, DivAddSubMult) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "36/2+2-4*2";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(32, test->evaluate());
}

TEST(OpTestDiv, DivSubMultAdd) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "36/2-3*2+5";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(35, test->evaluate());
}

TEST(OpTestDiv, DivMultAddSub) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "16/2*3+1-15";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(10, test->evaluate());
}

TEST(OpTestPow, Pow) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2^3";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(8, test->evaluate());
}

TEST(OpTestPow, PowAdd) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2^3+5";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(13, test->evaluate());
}

TEST(OpTestPow, PowSub) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2^3-5";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(3, test->evaluate());
}

TEST(OpTestPow, PowMult) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2^3*2";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(16, test->evaluate());
}

TEST(OpTestPow, PowDiv) {
    char* test_val[2];
    test_val[0] = "./calculator";
    test_val[1] = "2^3/4";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(2, test->evaluate());
}
