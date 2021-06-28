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
		return { "", "요청하신 내용을 찾을 수 없습니다" };
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
		AppendCommand("헬로 챗봇", "음식 관련 서비스를 담당하는 봇입니다");
		AppendCommand("추천 음식", "오늘은 치킨이 좋을 것 같아요");
	}
};
class GameBot sealed : public ChatBot
{
public:
	GameBot()
	{
		AppendCommand("헬로 챗봇", "게임 관련 서비스를 담당하는 봇입니다");
	}
};

int main(void)
{
	std::weak_ptr< ChatBot > wp;
	std::shared_ptr< FoodBot > chatBot01 = std::make_shared<FoodBot>();
	std::shared_ptr< GameBot > chatBot02 = std::make_shared<GameBot>();
	//std::cout << chatBot01->Request("헬로 챗봇") << std::endl;
	//std::cout << chatBot01->Request("추천 음식뽑아줘") << std::endl;

	
	/*
	weak_ptr은 shared_ptr과 비슷한 성향을 가지고 있지만 reference_count가 존재하지 않는다.
	wp = chatBot01; 이런식으로 shared_ptr을 wp에 copy를 하게 되면 자동으로 캐스팅이 된다.
	캐스팅됬었을 때 shared_ptr가 가리키고 있는 FoodBot이 약하게 연결되기 때문에
	reference_count의 수가 올라가지 않는다.
	if (auto obj = wp.lock()) {} 와 같이 weak_ptr에 있는 lock()을 해주면
	shared_ptr이 반환되는데 이때 반환이 되었을 때 오브젝트가 있으면 wp가 가리키고 있는
	오브젝트의 reference_count를 1증가시키고 오브젝트를 반환한다.
	만약 shared_ptr의 reference_count가 0이 되어서 release가 되었을 때
	weak_ptr이 가리키고 있는게 없기 때문에 lock()을 통해 반환을 했더라도 invalid가 되어서
	조건이 거짓이 리턴된다.
	따라서 weak_ptr은 해당 오브젝트가 이미 쓰여지고 있거나 없는 것의 여부를 분별 할 수 있는 포인터이다.


	*/
	wp = chatBot02;
	wp = chatBot01;

	//chatBot01.reset();

	if (auto obj = wp.lock())
	{
		std::cout << obj->Request("헬로 챗봇") << std::endl;
		std::cout << obj->Request("추천 음식뽑아줘") << std::endl;
	}
	return 0;
}