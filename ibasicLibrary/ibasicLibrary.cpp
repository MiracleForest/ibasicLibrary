#include <iostream>
#include "../include/icore/type/basic/number.hpp"
#include "../include/icore/type/basic/numberArray.hpp"
#include "../include/icore/type/type/type.hpp"

using std::operator""s;

int main(){

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


    system("pause");
    return 0;
}

