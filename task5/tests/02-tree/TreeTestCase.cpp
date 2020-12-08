//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include "gtest/gtest.h"
#include <algorithm>

TEST(LeapTestCase, NonExistingPath) {
    try {
        FileNode node = GetTree("/some_dummy_path", false);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const &err) {
        EXPECT_EQ(err.what(),std::string("Path not exist"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
};

TEST(LeapTestCase, NotADirectoryPath) {
    try {
        FileNode node = GetTree("/bin/cat", false);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const &err) {
        EXPECT_EQ(err.what(),std::string("Path is not directory"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
};

TEST(LeapTestCase, TestDirsOnly) {
    FileNode node = GetTree("/Users/nik", true);
    ASSERT_EQ(1, node.children.size());

    FileNode fileNode;
    fileNode.name = "folder";
    fileNode.is_dir = true;
    ASSERT_EQ(fileNode, node.children[0]);
};

TEST(LeapTestCase, TestNotDirsOnly) {
    FileNode node = GetTree("/Users/nik", false);
    ASSERT_EQ(2, node.children.size());
};