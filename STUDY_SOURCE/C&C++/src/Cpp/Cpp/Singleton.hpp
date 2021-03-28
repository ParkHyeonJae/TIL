#ifndef SINGLETON_H
#define SINGLETON_H
#include <stdexcept>

template<class T>
class Singleton
{
public:
	static T& getInstance()
	{
		static T so;
		if (s_deleted)
		{
			// This should never happen
			throw std::runtime_error("Call of deleted Singleton detected");
		}
		return so;
	}

	~Singleton() { s_deleted = true; }
private:
	static bool s_deleted;
};
template<class T>
bool Singleton<T>::s_deleted(false);


#endif // !SINGLETON_H