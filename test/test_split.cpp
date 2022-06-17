#include "../include/icore/type/basic/basic_istring.hpp"
#include "../include/icore/type/istring.hpp"

using i_string = i::core::type::istring;

int main()
{
    i_string str = "This is a string";
    auto result = str.split(' ');
    for (auto& s : result)
    {
        std::cout << s << std::endl;
    }
}