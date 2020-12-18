//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

#include "gtest/gtest.h"

TEST(LeapTestCase, NonLeap) {
    EXPECT_EQ(false,IsLeap(2003));
    EXPECT_EQ(false,IsLeap(2007));
    EXPECT_EQ(false,IsLeap(2013));
    EXPECT_EQ(false,IsLeap(1900));
};

TEST(LeapTestCase, Leap) {
    EXPECT_EQ(true,IsLeap(2004));
    EXPECT_EQ(true,IsLeap(2008));
    EXPECT_EQ(true,IsLeap(2000));
};

TEST(LeapTestCase, InvalidArgument) {
    ASSERT_THROW(IsLeap(-2), std::invalid_argument);
};
