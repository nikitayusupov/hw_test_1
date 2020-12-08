//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

#include "gtest/gtest.h"

TEST(AddTestCase, PositiveAdd) {
    EXPECT_EQ(5,Add(2, 3));
};

TEST(AddTestCase, NegativeAdd) {
    EXPECT_EQ(-5,Add(-2, -3));
};

TEST(AddTestCase, ZeroSum) {
    EXPECT_EQ(0,Add(5, -5));
};