// hours wasted: 3

// yeah nevermind I give up on this lol

// g++ -std=c++17 -lpcrecpp -o program.out program.cpp
#include <iostream>
#include <pcrecpp.h>

int main() {
    /*
    std::string text = "10 2 / 3 + 7 4";
    
    std::regex rgx("([0-9]+|[\\/*+-])\\s+");

    auto operands_begin = std::sregex_iterator(text.begin(), text.end(), rgx);
    auto operands_end = std::sregex_iterator();

    for (std::sregex_iterator itr = operands_begin; itr != operands_end; ++itr)
    {
        std::cout << itr->str() << '\n';
    }
    */

    std::string s;
    pcrecpp::RE re("(Item Name: meleeToolRepairT\\d\\K(.*))|(Item Name: meleeToolAxeT\\d\\K(.*))");
    re.FullMatch("Item Name: meleeToolAxeT1IronFireaxe", &s);
    std::cout << s << std::endl;
    
    return 0;
}