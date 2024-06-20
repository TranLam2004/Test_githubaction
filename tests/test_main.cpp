#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <sstream>

bool compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        return false;
    }

    std::string line1, line2;
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) {
            return false;
        }
    }

    // Kiểm tra xem cả hai file có độ dài giống nhau không
    return f1.eof() && f2.eof();
}

TEST(FileComparisonTest, CompareOutput) {
    system("../build/main"); // Chạy chương trình chính
    EXPECT_TRUE(compareFiles("tests/output.txt", "tests/expected_output.txt"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
