#include <Windows.h>
#include <map>
#include <list>
#include <string>

using namespace std;
#define PLAYERID 0

class Player
{
private:
	DWORD PlayerID;
	string PlayerName;
	DWORD PlayerLevel;
public:
	DWORD GetPlayerID() { return PlayerID; }
	VOID SetPlayerID(DWORD PlayerID) { this->PlayerID = PlayerID; }


};

class Character abstract
{
protected:
	int damage;

	virtual VOID SetDamage() = 0;
};
class Archer : Character 
{
	VOID SetDamage() override;
};

class Soldier : Character
{
	VOID SetDamage() override;
};

class MySingleThreadGameServer
{
	class Room
	{
		string m_roomName;
		list<Player> m_players;
		list<Character> m_characters;
	};
	map<, 
};


int main()
{

	return 0;
}

VOID Archer::SetDamage()
{
	damage = 5;
	return;
}

VOID Soldier::SetDamage()
{
	damage = 15;
	return;
}
