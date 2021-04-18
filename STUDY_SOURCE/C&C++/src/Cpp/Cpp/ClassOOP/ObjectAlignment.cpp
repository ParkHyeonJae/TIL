#include <iostream>

class Cat_16
{
public:
    void speak();
private:
    double d8;      // 8 bytes
    int i4a;        // 4 bytes
    int i4b;        // 4 bytes
};      // 16 bytes

class Cat_24
{
public:
    void speak();
private:
    int i4a;        // 4 bytes
                    // padding: + 4bytes
    double d8;      // 8 bytes
    int i4b;        // 4 bytes
                    // padding: + 4bytes
};      // 24 bytes


// CacheLine 크긱가 64byte이므로 class 크기가 24bytes면 멀티프로세서에서 배열의 일부를 여러 코어에 접근할 수 있게되고, 
// FalseSharing이 발생할 수 있기때문에 optimization을 위하여 32bytes로 맞췄다.
class alignas(32) Cat_32
{
public:
    void speak();
private:
    int i4a;        // 4 bytes
                    // padding: + 4bytes
    double d8;      // 8 bytes
    int i4b;        // 4 bytes
                    // padding: + 4bytes
};      // 24 bytes

Cat_16 static_cat;      // 컴파일 타임에 static 메모리 공간에 차지

int main(void)
{
    Cat_16 cat_16;      // Stack 공간에 차지
    std::cout << "cat_16 : " << sizeof(cat_16) << "\n";

    Cat_24 cat_24;
    std::cout << "cat_24 : " << sizeof(cat_24) << "\n";

    
    Cat_32 cat_32;
    std::cout << "cat_32 : " << sizeof(cat_32) << "\n";


    Cat_16 *cat_heap = new Cat_16;      // Heap 공간에 8byte 차지
    delete cat_heap;
    return 0;
}