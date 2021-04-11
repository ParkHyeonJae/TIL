#include <iostream>
#include <string>

class Cat
{
public:
    void SetName(std::string name)      // L-Value를 인자로 넣을 시 1번의 복사가 일어나고 R-Value로 넣을 시 Copy Elision이 일어나면서 복사가 일어나지 않는다.
    {
        mName = std::move(name);
    }

private:
    std::string mName;
};

void storeByLRef(std::string & s)
{
    std::string b = s;
    s = "adasd";
}


int main(void)
{
    std::string a = "abc";
    storeByLRef(a);
    std::cout << a << "\n";

    return 0;
}