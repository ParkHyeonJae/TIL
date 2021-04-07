#include <iostream>

/*
* 
* Stack Memory만 있는게 아닌, HEAP Memory까지 존재하는 이유는?
* 그 이유에는 세 가지의 이유가 있다.
* 
* 첫째, 생명 주기(Life Cycle)의 차이
* - Stack Memory는 특정 함수에 진입하게 되면 StackFrame 단위로 Stack에 쌓이게 되는데,
*  이때 함수가 끝나게 되면 Stack에 쌓인 정보가 Pop이 되면서 사라지게 된다.
*  하지만 Heap Memory를 사용하게 되면 프로그래머가 직접 제거를 해주지 않는 이상 게속 Heap Memory에 상주하게 된다.(C++ 기준)
* 
* 두번째, 라지 사이즈(Large Size)
* - 모든 데이터를 Stack에서 관리하기에는 용량이 턱없이 부족하기 때문에
*  실질적인 데이터는 HEAP 영역에 할당해두고 할당된 영역의 주소정보만 Stack에 저장되서 필요할 때 해당되는
*  주소를 이용하는 방식으로 진행된다.
* 
* 세번째, Dynamic Alloc (runtime)
* - 프로그램에서 사용할 자원들은 컴파일 타임에 컴파일러가 크기를 정해주는데, 
* 그래서는 실행중에 사이즈나 다른 경우에 따른 상황에 대처하기가 어려워진다.
* 따라서 Heap에 동적으로 할당을 하여, 좀 더 유연한 프로그램을 제작할 수 있어진다.
* 
* 
*/



int main(void)
{
	int* ip;
	ip = new int;
	*ip = 100;

	delete ip;



	return 0;
}