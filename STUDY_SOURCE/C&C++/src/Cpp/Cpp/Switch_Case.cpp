#include <iostream>


int main(void)
{
	/*
	Switch Case 내부적 동작 원리
	
	switch (x) {
	case 1:
		break;
	case 2:
		std::cout << "2" << "\n";
		[[__fallthrough]]
	case 3:
		std::cout << "3" << "\n";
		break;
	default:
		break;
	}

	내부적으로 동작은 이렇다
	
	if(x <= 3)		// 3보다 작을 경우
	{
		code = jumpTable[x];		// 점프 테이블에서 코드를 가져온다.
		goto code;			// 해당 코드가 위치한 번지로 이동한다.
	}
	else{ goto default; }		// 3보다 작지 않을 경우에는 default로 이동한다.

	이런식으로 점프테이블에서 해당되는 주소를 가져와서 해당 주소로 점프를 시켜주는
	구조로 되어있으며 break;문을 쓰게 된다면 ret라는 opcode가 작동하게 되면서 함수를 바로 
	빠져나가게 된다.
	때문에 break;를 쓰면 switch문에서 바로 빠져나가게 되며, 만약 break;를 쓰지 않게되면
	ret 이라는 opcode가 실행이 되지 않기때문에 바로 다음 번지로 이동이 되게 된다.

	따라서 연속으로 동일한 처리를 하려면 break;를 없애주면 되긴 한데, 이러면 
	경고 메시지를 줄 가능성이 있기때문에 [[__fallthrough]]를 사용한다.
	*/

	switch (2) {
	case 1:
		break;
	case 2:
		std::cout << "2" << "\n";
		[[__fallthrough]]
	case 3:
		std::cout << "3" << "\n";
		break;
	default:
		break;
	}
	

	return 0;
}