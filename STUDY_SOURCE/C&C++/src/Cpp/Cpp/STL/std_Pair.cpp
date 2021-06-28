#include <iostream>
#include <string>

enum class ErrorCode
{
    error_code = -1,
    noError = 0
};

/*

자주 사용하는 경우는 struct로 묶어서 리턴을 하며,
자주 사용하지 않고, 하나의 파일 내에서 일회적으로 사용되는 경우 std::pair나 std::tuple을 통해 
값을 리턴한다.

*/


std::pair<int, ErrorCode> divide(const int32_t& a, const int32_t& b)
{
    if(b == 0)
    {
        return {0, ErrorCode::error_code};
    }

    return {a/b, ErrorCode::noError};
}



int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    auto pair = divide(4, 2);

    std::cout << pair.first << " " << (int)pair.second << std::endl;

    pair = divide(4, 0);

    std::cout << pair.first << " " << (int)pair.second << std::endl;
    
    auto [fir, sed] = divide(90, 2);
    std::cout << fir << " " << (int)sed << std::endl;
    return 0;
}