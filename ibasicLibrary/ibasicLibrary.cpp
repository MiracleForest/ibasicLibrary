#include <iostream>
// #include "../include/icore/type/basic/number.hpp"
// #include "../include/icore/type/basic/numberArray.hpp"
// #include "../include/icore/type/type/type.hpp"
#include "../include/icore/type/basic/istring.hpp"

using std::operator""s;

using String = i::core::type::basic::istring<std::string>;
// 模板约束正常
// using String = i::core::type::basic::istring<char>;


void testIstring()
{
    std::cout << "========== istring test ==========\n";
    std::cout << "流输入输出测试: \n";
    String str = "Hello Everyone!";
    str << "Current year is "
        << String::valueOf(2022)
        << ". This is i language istring test string."
        << "End.";
    std::cout << "str = " << str << std::endl;

    std::cout << "字符串分割测试: \n";
    String str1 = "C C++ Java Python Ruby Nojs Javascript PHP";
    std::vector<String> strs = str1.split(' ');
    for (auto& it : strs){
        std::cout << it << std::endl;
    }

    std::cout << "正则表达式测试: \n";
    String str3 = "https://cn.bing.com?key=xxx";
    if (str3.match(std::regex("http[sS]{1}://cn.bing.com[?]{1}(.+=.+)+"))){
        std::cout << "正确匹配\n";
    }
}

int main(){

    /*
    std::cout << i::core::itype::getTypeString<std::string>() << std::endl;
    std::cout << i::core::itype::getTypeString("aaa-") << std::endl;
    std::cout << i::core::itype::getTypeString("bbb-"s) << std::endl;

    std::cout << i::core::itype::toStdString("bbb-"s) << std::endl;
    std::cout << i::core::itype::toStdString(123) << std::endl;
    std::cout << i::core::itype::toStdString(1.23) << std::endl;
    std::cout << i::core::itype::toStdString(1.000000000000000000000000000000000000112312321321) << std::endl;
    std::cout << i::core::itype::toStdString(L"---") << std::endl;
    std::cout << i::core::itype::toStdString('A') << std::endl;
    std::cout << i::core::itype::toStdString(L'B') << std::endl;

    i::core::type::basic::number<int> test = 2;
    test = i::core::type::basic::number<int>(1000);
    std::cout << test << std::endl;
    test = i::core::type::basic::number<int>(1234);
    std::cout << test << std::endl;
    test.reset();
    std::cout << test << std::endl;

    i::core::type::basic::numberArray<int,10> test2;
    */

    testIstring();

#ifdef __WINDOWS__
    system("pause");
#endif
    return 0;
}

