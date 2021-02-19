#include <vector>

std::vector<int> v;


std::vector<int>::iterator iter = v.begin();
// 기존에는 위와 같이 그 형태에 맞춰서 타입을 적어줘야 했지만

// C++0x에서는 auto 키워드를 통해서 컴파일 타임에 컴파일러가 형태를 판단시켜준다.
auto auto_iter = v.begin();

// *,&,const,volatile등도 가능

int main(void)
{
	return 0;
}