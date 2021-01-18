#include <iostream>

// 포인터로 주소값을 매개변수로 받아서 참조한 number의 값을 변경
int change_val(int* p)
{
	*p = 3;

	return 0;
}

// C에서 C++ 로 넘어오면서 가능해짐, 참조자를 이용함
// 참조자(&)는 별명을 지어주는 것과 같다. 즉 p는 다른말로 하면 number가 되는 것이다.
int change_val(int& p)
{
	p = 12;

	return 0;
}

int & function()
{
	int a = 2;
	return a;
}
int main(void)
{
//	int test_a = function();
//	test_a = 10; <- 위와 같이 함수의 지역 안에서 선언된 변수가 리턴되면서 사라졌는데 그 레퍼런스를 가리키고 있으므로 위험하게 된다.
	// 이를 약하게 결합, 즉 달랑달랑 거린다고 해서 댕글링 레퍼런스(Dangling Reference)라고 부른다.

	int number = 5;

	change_val(&number);


	change_val(number);

	std::cout << number << std::endl;



	int a = 3;
	int & another_a = a;		// another_a 는 a와 같음

	// 두가지 방법 모두 둘중에 하나면 하더라도 a랑 another_a랑 모두 적용이 된다.
	another_a = 20;
	a = 20;
	std::cout << a << std::endl;
	std::cout << another_a << std::endl;


	/*
	이렇게 까지 보게되면 참조자(&)랑 포인터(&)의 차이에 대해서
	의문이 생기게 된다.

	차이점에 대해서 간단하게 요약하자면
	- 레퍼런스로 되어있으면 반드시 타겟을 지정해 줘야한다.
	ex) int & a = b; -> O
	ex) int & a; -> X
	- 레퍼런스의 타겟이 한번 지정이 되면 다른 타겟으로 변경이 불가능하다.
	int b = 10;
	int& another_b = b;

	int c = 15;
	another_b = c;

	위와 같은 경우에, another_b의 타깃을 b로 정하고 또 c를 대입해서
	타겟이 변경된 것처럼 보이는데, 이건 절대 아니다.
	이는 another_b = 15 랑 같은 의미가 된다.

	확인차 아래에 c = 40을 추가해보고 출력을 해보면 another_b에 값의 변동이 되질 않는 것을 볼 수 있다.

	반면에 포인터는 기존에 적용된 타깃의 주소를 버리고 새로운 타깃으로 변경이 가능하다. (레퍼런스와 포인터의 차이점)

	- 레퍼런스는 메모리 상에 존재하지 않을 수 있다.
	int b = 10;
	int &another_b = b;
	와 같이 동일한 호출 스택 안에서 레퍼런스를 사용한 경우 컴파일러 입장에서는 굳이 another_b의 공간을 할당할 필요가 없다.
	왜냐하면 어차피 another_b를 쓰나 b를 쓰냐 결과는 똑같기 때문이다.
	하지만 다른 호출스택의 경우에는 달라질 수 있다.

	- 포인터보다 레퍼런스를 사용했을 때 더 보기가 깔끔해진다.
	아무래도 포인터는 주소값이나 값을 넣을 때 역참조나 레퍼런스 기호를 사용하는데 레퍼런스로 선언을 하게 되면 필요가 없어지기 때문

	*/
	
	int b = 10;
	int& another_b = b;

	int c = 15;
	another_b = c;
	c = 40;
	std::cout << another_b << std::endl;


	// int& ref = 10; <- 이는 에러가 뜨게 된다.
	const int& ref = 10;		// <- 대신 상수로 정해주면 에러가 안뜬다.
	
	int e = 77, f = 88;
	int arr[2] = { e, f };

	int (&refArr)[2] = arr;
	arr[0] = 99;
	std::cout << refArr[0] << std::endl;


	



	return 0;
}