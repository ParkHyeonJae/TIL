#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <utility>

typedef std::pair< std::string, std::string > STRPAIR;

class ChatBot
{
public:
	virtual std::string Request(std::string name)
	{
		return Answer(std::move(name));
	}

	virtual void AppendCommand(std::string command, std::string answer)
	{
		m_commandTable.emplace(std::move(command), std::move(answer));
	}

protected:
	virtual STRPAIR
		Command(std::string&& command)
	{
		for (auto& pair : m_commandTable)
		{
			if (command.find(pair.first) != std::string::npos)
				return pair;
		}
		return { "", "��û�Ͻ� ������ ã�� �� �����ϴ�" };
	}
	virtual std::string Answer(std::string&& request)
	{
		return Command(std::move(request)).second;
	}

	
private:
	std::map<std::string, std::string> m_commandTable;
};

class FoodBot sealed : public ChatBot
{
public:
	FoodBot()
	{
		AppendCommand("��� ê��", "���� ���� ���񽺸� ����ϴ� ���Դϴ�");
		AppendCommand("��õ ����", "������ ġŲ�� ���� �� ���ƿ�");
	}
};
class GameBot sealed : public ChatBot
{
public:
	GameBot()
	{
		AppendCommand("��� ê��", "���� ���� ���񽺸� ����ϴ� ���Դϴ�");
	}
};

int main(void)
{
	std::weak_ptr< ChatBot > wp;
	std::shared_ptr< FoodBot > chatBot01 = std::make_shared<FoodBot>();
	std::shared_ptr< GameBot > chatBot02 = std::make_shared<GameBot>();
	//std::cout << chatBot01->Request("��� ê��") << std::endl;
	//std::cout << chatBot01->Request("��õ ���Ļ̾���") << std::endl;

	
	/*
	weak_ptr�� shared_ptr�� ����� ������ ������ ������ reference_count�� �������� �ʴ´�.
	wp = chatBot01; �̷������� shared_ptr�� wp�� copy�� �ϰ� �Ǹ� �ڵ����� ĳ������ �ȴ�.
	ĳ���É���� �� shared_ptr�� ����Ű�� �ִ� FoodBot�� ���ϰ� ����Ǳ� ������
	reference_count�� ���� �ö��� �ʴ´�.
	if (auto obj = wp.lock()) {} �� ���� weak_ptr�� �ִ� lock()�� ���ָ�
	shared_ptr�� ��ȯ�Ǵµ� �̶� ��ȯ�� �Ǿ��� �� ������Ʈ�� ������ wp�� ����Ű�� �ִ�
	������Ʈ�� reference_count�� 1������Ű�� ������Ʈ�� ��ȯ�Ѵ�.
	���� shared_ptr�� reference_count�� 0�� �Ǿ release�� �Ǿ��� ��
	weak_ptr�� ����Ű�� �ִ°� ���� ������ lock()�� ���� ��ȯ�� �ߴ��� invalid�� �Ǿ
	������ ������ ���ϵȴ�.
	���� weak_ptr�� �ش� ������Ʈ�� �̹� �������� �ְų� ���� ���� ���θ� �к� �� �� �ִ� �������̴�.


	*/
	wp = chatBot02;
	wp = chatBot01;

	//chatBot01.reset();

	if (auto obj = wp.lock())
	{
		std::cout << obj->Request("��� ê��") << std::endl;
		std::cout << obj->Request("��õ ���Ļ̾���") << std::endl;
	}
	return 0;
}