#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <iostream>

bool compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        return false;
    }

    std::string line1, line2;
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) {
            std::cerr << "Mismatch found:\n"
                      << "Expected: " << line2 << "\n"
                      << "Got: " << line1 << "\n";
            return false;
        }
    }

    bool eof1 = f1.eof();
    bool eof2 = f2.eof();
    if (!eof1 || !eof2) {
        std::cerr << "Files have different lengths\n";
        return false;
    }

    return true;
}

TEST(FileComparisonTest, CompareOutput) {
    int result = system("../src/main"); // Chạy chương trình chính và tạo file output.txt
    ASSERT_EQ(result, 0) << "Main program failed to execute";

    bool files_are_equal = compareFiles("tests/output.txt", "tests/expected_output.txt");
    EXPECT_TRUE(files_are_equal) << "Output file does not match expected output";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
