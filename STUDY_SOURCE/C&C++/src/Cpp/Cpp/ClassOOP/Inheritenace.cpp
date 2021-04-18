#include <iostream>


class Base
{
    private:
    int pri;
    protected:
    int pro;

    public:
    void SetPRI(int n)
    {
        pri = n;
    }

    void SetPRO(int n)
    {
        pro = n;
    }
};

class Derived_public : public Base
{
public:
    void test()
    {
        Base::pro = 34;
    };
};


class Derived_protected : protected Base
{
public:
    void test()
    {
        Base::pro = 34;
    };
};



class Derived_private : private Base
{
public:
    void test()
    {
        Base::pro = 34;
    };
};


int main(void)
{
    Derived_public derived_public;
    derived_public.SetPRI(20);
    derived_public.SetPRO(30);
    derived_public.test();

    Derived_protected derived_protected;
    derived_protected.test();
    //derived_protected.SetPRI(20);     // public이 protected가 되면서 접근 불가
    //derived_protected.SetPRO(30);

    Derived_private derived_private;
    derived_private.test();
    //derived_private.SetPRI(40);       // public이 private가 되면서 접근 불가
    //derived_private.SetPRO(50);
    return 0;
}