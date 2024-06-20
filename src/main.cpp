#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream testcase("tests/testcase.txt");
    std::ofstream output("tests/output.txt");

    if (!testcase.is_open() || !output.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(testcase, line)) {
        // Giả sử chương trình chỉ cần copy nội dung từ testcase.txt sang output.txt
        output << line << std::endl;
    }

    testcase.close();
    output.close();

    return 0;
}
