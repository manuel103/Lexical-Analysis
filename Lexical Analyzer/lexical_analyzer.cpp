#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <vector>

int main()
{
    std::string str = " f = 78 * 79 + 90 ";
    // std::cin >> "Enter your expression";

    // using std::vector in this order
    std::vector<std::pair<std::string, std::string>> v{
        {"[0-9]+", "... is a NUMBER"},
        {"[a-z]+", "... is an IDENTIFIER"},
        {"\\*|\\+|=", "... is an OPERATOR"}};

    std::string reg;

    for (auto const &x : v)
        reg += "(" + x.first + ")|";

    reg.pop_back();
    std::cout << reg << std::endl;

    std::regex re(reg, std::regex::extended);

    auto words_begin = std::sregex_iterator(str.begin(), str.end(), re);
    auto words_end = std::sregex_iterator();

    for (auto it = words_begin; it != words_end; ++it)
    {
        size_t index = 0;

        for (; index < it->size(); ++index)
            if (!it->str(index + 1).empty()) // determine which submatch was matched
                break;

        std::cout << it->str() << "\t" << v[index].second << std::endl;
    }

    return 0;
}
