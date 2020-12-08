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
    try {
        bool isLeap = IsLeap(-2);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const &err) {
        EXPECT_EQ(err.what(),std::string("Year must be greater than 0"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
};