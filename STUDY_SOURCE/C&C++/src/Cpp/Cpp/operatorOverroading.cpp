#include <iostream>

class Block
{
public:
	Block() {}

	Block(const int n1, const int n2) : n1(n1), n2(n2) {}

	Block operator+(int num)
	{
		return Block(n1 + num, n2 + num);
	}

	friend Block operator+(int num, Block ref);

	Block operator++()
	{
		n1 += 1;
		n2 += 1;
		return *this;
	}
	Block operator++(int)
	{
		Block temp(*this);

		n1 += 1;
		n2 += 1;
		return temp;
	}

	void ShowInfo() const
	{
		std::cout << n1 << " : " << n2 << "\n";
	}
private:
	int n1;
	int n2;
};

Block operator+(int num, Block ref)
{
	return Block(ref.n1 + num, ref.n2 + num);
}

int main(void)
{
	Block b1(10, 20);

	Block b2 = 20 + b1 + 50;
	b1.ShowInfo();
	b2.ShowInfo();

	Block b_t1(10, 30);
	Block b_t2(10, 30);
	Block b3 = ++b_t1;
	Block b4 = b_t2++;
	b3.ShowInfo();
	b4.ShowInfo();

	return 0;
}

