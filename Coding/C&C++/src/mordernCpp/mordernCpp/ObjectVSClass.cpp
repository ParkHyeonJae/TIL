#include <iostream>

class MobilePhone
{
public:
	MobilePhone(const std::string& name) : name(name) {}
private:
	std::string name;
};

int main()
{
	// Object 와 Class 의 차이점
	MobilePhone phone01("S10");		// MobilePhone 은 Class, Object는 생성된 Phone01를 가리킴

	/*
	Object 생성 시 주의할 점
	JAVA 개발을 해셨던 사람들이하면 당연하게도 객체를 사용할 때
	MobilePhone * phone02 = new MobilePhone("S10");
	아래와 같이 new 키워드를 통해서 새로 할당 받고 사용을 하셔서
	C++ 개발할 때도 이런식으로 주로 사용하는 경우도 있다.

	하지만 C++ 의 개념은 JAVA와 좀 다른면이 있기에 new를 꼭 객체를 사용할 때마다 사용해서는 안된다.

	C++ 에서는 포인터 변수에 new를 사용하게 되면 Heap에 메모리 주소가 생기게 된다.
	Heap에 생기기 때문에 반드시 delete 시켜줘야 만 한다.

	Object랑 Instance랑 차이점은 결과적으로 봤을 때는 두 용어 모두 비슷한 의미인것 같다.
	일단 C++ 쪽에서는 Instnace보다는 Object를 더 많이 사용하는 것 같고, Instance는 주로 싱글턴으로 생성된 특별한 경우일 때 부르는 것 같다.

	JAVA에서는
	MobilePhone phone01;
	phone01 = new MobilePhone();
	이런 코드가 있을 때,
	MobilePhone가 class이며, 
	phone01이 object,
	phone01 = new MobilePhone()로 받았을 때 Instance라고 부르는 것 같다.
	*/
	
	return 0;
}