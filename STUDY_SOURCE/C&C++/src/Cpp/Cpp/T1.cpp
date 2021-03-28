#include <iostream>

/*
컴파일 프로세스는 이렇다.
먼저 각 cpp파일들과 헤더(.h)파일들을 #include를 통해서 하나로 통합시켜줌으로써 Translation Unit을 만들게 되고 이들을 오브젝트(.o)파일로 컴파일러가 바꿔주고, 이러한 오브젝트 파일들을
링커가 링킹을 해주면서 하나의 excutable(exe)파일로 변환을 시켜주는 프로세스이다.

이때 오브젝트 파일들을 링커가 링킹을 해주는 과정에서 Global Variable로 동일한 변수 int a 가 존재하면 이는 충돌이 일어나게 된다. (Error	LNK2005	"int a" (?a@@3HA) already defined in T1.obj	Cpp)

따라서 이를 Global Variable이 internal인지 external인지 어떻게 정의해주냐에 따라서 linkage의 과정이 달라진다.
먼저 extern int a; 를 통해서 external linkage로 선언 하였을 때, 이는 외부의 Translation Unit에 정의되어 있는 a를 가져와서 쓰겠다고 알려주게 되면서
외부에 int a = 20;이라고 정의되어 있다면 링크 프로세스를 진행하면서 최종적으로 a가 20이 된다.

static 키워드를 통해 internal linkage로 선언을 하게 되면, 이는 내부적으로 정의되어있는 하나의 Translation Unit으로만 사용이 되기 때문에 외부에 존재하는 다른
Translation Unit에서 사용할 수 없게 된다.

따라서 Global Variable을 cpp안에서 사용하게 된다면 static을 붙여주고 바깥쪽의 link를 막는것이 좋다.

*/

static int a;

int main(void)
{
	std::cout << a;
	return 0;
}