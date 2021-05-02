#include <iostream>
#include <unordered_set>
#include <string>

int main(void)
{
	/*
	* 
	* unordered_set
	* 
	* find, insertion, deletion�� O(1)�� �ð����⵵�� ������.
	* �̴� hash������� ���۵Ǿ��� ������ ������ ��
	* 
	* emplace�� �߰��� �����ν� �̸� hash�� ��ȯ�ϰ� hash���� ���� ���ϴ� bucket�� ���� �־��ش�.
	* ��Ŷ�� ��ġ�� hash % buketCount�� ����ϰ�
	* ��Ŷ ����� �ʰ��ϰԵǾ��� ��� ���ο� ��Ŷ�� �߰����ִµ� �̶� ������ Hash���� ��� ��������� �Ǽ� O(n)�� ���⵵�� ������ �ȴ�.
	* �̸� �����ϱ� ���ؼ� ������ �ʿ��� ���� reserveŰ���带 ���� �̹� �޾Ƶΰ� �Ǹ� reHashing�� �� �ʿ䰡 ��������.
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