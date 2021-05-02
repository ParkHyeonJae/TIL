#include <iostream>
#include <memory>

class CGameCompany
{
public:
    CGameCompany() = default;
    virtual ~CGameCompany() = default;

    virtual void Introduce();     // virtual 키워드를 붙이면 클래스 사이즈가 증가하게 되는데 이는 VTable 포인터가 생기기 때문이다.
};

void CGameCompany::Introduce()      // CGameCompany의 VTable은 이 함수를 가리키고 있음
{
    std::cout << "This is Game Company" << "\n";
};

class CLoadComplete : public CGameCompany
{
public:
    void Introduce() override;      // 부모에 이어서 자식 클래스도 똑같히 VTable을 가지고 있으며 이때 자식 테이블의 VTable은 CLoadComplete::Introduce() 을 가리킨다.
};

void CLoadComplete::Introduce()     // CLoadComplete VTable은 이 함수를 가리키고 있음
{
    std::cout << "This is LoadComplete Company that I Like" << "\n";
};


class CMafGames : public CGameCompany
{
public:
    void Introduce() override;
};

void CMafGames::Introduce()     // CMafGames VTable은 이 함수를 가리키고 있음
{
    std::cout << "This is CMafGames Company that I Like" << "\n";
};

class CShiftup : public CGameCompany
{
public:
    void Introduce() override;
};

void CShiftup::Introduce()      // CShiftup VTable은 이 함수를 가리키고 있음
{
    std::cout << "This is Shiftup Company that I Like" << "\n";
};

class CAwesomePiece : public CGameCompany
{
public:
    void Introduce() override;
};

void CAwesomePiece::Introduce()      // CAwesomePiece VTable은 이 함수를 가리키고 있음
{
    std::cout << "This is CAwesomePiece Company that I Like" << "\n";
};


// virtual 키워드를 붙이면 클래스 사이즈가 증가하게 되는데 이는 VTable 포인터가 생기기 때문이다.
// VTable 포인터는 virtual로 되어있는 함수들을 가리키게 된다.
int main(void)
{

    //std::cout << sizeof(CGameCompany) << "\n";

    // CGameCompany pointer 사이즈 + heap에 할당된 CLoadComplete의 사이즈
    // Introduce 호출 시 heap에 실질적으로 할당된 CLoadComplete안에 있는  CLoadComplete::Introduce()를 호출하게 된다.
    std::unique_ptr<CGameCompany> somethingCompany = std::make_unique<CLoadComplete>();
    somethingCompany->Introduce();
    somethingCompany.reset();

    somethingCompany = std::make_unique<CMafGames>();
    somethingCompany->Introduce();

    return 0;
}