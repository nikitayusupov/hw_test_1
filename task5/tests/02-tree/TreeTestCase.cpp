//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include "gtest/gtest.h"
#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>

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
    ASSERT_THROW(GetTree("/bin/cat", false), std::invalid_argument);
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
    boost::filesystem::create_directories("some_test_folder/some_test_subfolder");
    std::ofstream outfile ("some_test_folder/test.txt");
    outfile.close();

    FileNode node = GetTree("some_test_folder", false);
    ASSERT_EQ(2, node.children.size());

    node = GetTree("some_test_folder", true);
    ASSERT_EQ(1, node.children.size());

    boost::filesystem::remove("some_test_folder/some_test_subfolder");
    boost::filesystem::remove("some_test_folder/test.txt");
    boost::filesystem::remove("some_test_folder");
};
