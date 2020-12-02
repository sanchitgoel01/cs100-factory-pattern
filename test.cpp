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

TEST(OpTest, AddAddAddAdd) {
    char* test_val[2]; 
    test_val[0] = "./calculator"; 
    test_val[1] = "5+4+3+2";
    BaseFactory* factory;
    Base *test = factory->parse(test_val,2);
    EXPECT_EQ(14, test->evaluate());
}

