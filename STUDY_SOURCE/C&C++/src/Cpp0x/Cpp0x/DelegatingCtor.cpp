class Example
{
	int x, y, z;
	Example(int x, int y, int z) : x(x), y(y), z(z)
	{

	}

	// ������ �ȿ� �����ڸ� ȣ���� �����ϴ�
	Example(const Example& other) : x(other.x), y(other.y), z(other.z)
	{

	}
};