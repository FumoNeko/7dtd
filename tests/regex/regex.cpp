// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include <regex>

int main() {
    std::string text = "10 2 / 3 + 7 4";
    std::regex rgx("([0-9]+|[\\/*+-])\\s+");

    auto operands_begin = std::sregex_iterator(text.begin(), text.end(), rgx);
    auto operands_end = std::sregex_iterator();

    for (std::sregex_iterator itr = operands_begin; itr != operands_end; ++itr)
    {
        std::cout << itr->str() << '\n';
    }
}