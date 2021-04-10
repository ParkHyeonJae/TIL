#include <string>

void Value(std::string s)       // 복사 1
{
    std::string b = s;      // 복사 2
}

void Reference(std::string& s)
{
    std::string b = s;      // 복사 1
}

void RValue_Reference(std::string&& s) 
{
    std::string b = std::move(s);

    // 복사 0
}

int main(void)
{
    std::string a = "abc";
    Value(a);
    Reference(a);
    RValue_Reference("abc");
    
    return 0;
}