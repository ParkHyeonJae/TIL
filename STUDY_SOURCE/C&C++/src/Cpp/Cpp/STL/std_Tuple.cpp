#include <iostream>
#include <string>
#include <tuple>

using ushort = unsigned short;

std::tuple<ushort, std::string, std::string> get_student()
{
    return {29, "A", "Hyeun Jae - Park"};
}


int main(void)
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    auto tuple = get_student();
    std::cout << "AGE : " << std::get<0>(tuple) << "\n";
    std::cout << "GRADE : " << std::get<1>(tuple) << "\n";
    std::cout << "NAME : " << std::get<2>(tuple) << "\n";

    // C++ 17
    // auto [age, grade, name] = get_student();
    // std::cout << "AGE : " << age << "\n";
    // std::cout << "GRADE : " << grade << "\n";
    // std::cout << "NAME : " << name << "\n";

    return 0;
}
