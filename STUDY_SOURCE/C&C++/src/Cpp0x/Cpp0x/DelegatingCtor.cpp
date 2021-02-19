class Example
{
	int x, y, z;
	Example(int x, int y, int z) : x(x), y(y), z(z)
	{

	}

	// 생성자 안에 생성자를 호출이 가능하다
	Example(const Example& other) : x(other.x), y(other.y), z(other.z)
	{

	}
};