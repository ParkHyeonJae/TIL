#include <iostream>
#include <unordered_set>
#include <string>

int main(void)
{
	/*
	* 
	* unordered_set
	* 
	* find, insertion, deletion이 O(1)의 시간복잡도를 가진다.
	* 이는 hash기반으로 제작되었기 때문에 가능한 일
	* 
	* emplace를 추가를 함으로써 이를 hash로 변환하고 hash값에 따라서 원하는 bucket에 값을 넣어준다.
	* 버킷의 위치는 hash % buketCount로 계산하고
	* 버킷 사이즈를 초과하게되었을 경우 새로운 버킷을 추가해주는데 이때 기존의 Hash값을 모두 변경해줘야 되서 O(n)의 복잡도를 가지게 된다.
	* 이를 방지하기 위해서 사전에 필요한 수를 reserve키워드를 통해 이미 받아두게 되면 reHashing을 할 필요가 없어진다.
	* 
	*/
	std::unordered_set<std::string> UOrdSet;

	UOrdSet.emplace("abc");
	UOrdSet.emplace("def");
	UOrdSet.emplace("ghi");
	UOrdSet.emplace("jkl");
	
	std::cout << UOrdSet.bucket_count() << "\n";

	std::cout << std::hash<std::string>{}("abc")  << " : " << UOrdSet.bucket("abc") << "\n";
	std::cout << std::hash<std::string>{}("def")  << " : " << UOrdSet.bucket("def") << "\n";
	std::cout << std::hash<std::string>{}("ghi")  << " : " << UOrdSet.bucket("ghi") << "\n";
	std::cout << std::hash<std::string>{}("jkl")  << " : " << UOrdSet.bucket("jkl") << "\n";
	
	return 0;
}