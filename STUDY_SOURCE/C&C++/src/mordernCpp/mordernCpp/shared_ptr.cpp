#include <memory>
#include <iostream>
#include <vector>

class Book
{
public:
	Book(std::string name, int price) 
		: name(std::move(name)), price(price) {}

	void GetInfo() const;

	std::string GetName();
	int GetPrice();

	class BookBuilder
	{
	public:
		BookBuilder() : name("å1"), price(0) {}

		BookBuilder SetName(std::string name)
		{
			this->name = std::move(name);
			return (*this);
		}
		BookBuilder SetPrice(int price)
		{
			this->price = price;
			return (*this);
		}

		Book Build()
		{
			return Book(name, price);
		}
	private:
		std::string name;
		int price;
	};
private:
	std::string name;
	int price;
};
void Book::GetInfo() const
{
	std::cout << "Book Name : " << name << ", Price : " << price << std::endl;
}
std::string Book::GetName()
{
	return name;
}
int Book::GetPrice()
{
	return price;
}


class Library
{
public:
	Library() { index.reserve(20); }
	~Library() {}
	void AppendBook(std::shared_ptr<Book> book);
	std::vector<std::shared_ptr<Book>> GetIndex() const;
	void PrintBookInfo() const;
private:
	std::vector<std::shared_ptr<Book>> index;
};
void Library::AppendBook(std::shared_ptr<Book> book)
{
	index.emplace_back(std::move(book));
}
std::vector<std::shared_ptr<Book>> Library::GetIndex() const
{
	return index;
}

void Library::PrintBookInfo() const
{
	for (auto& book : index)
	{
		book->GetInfo();
	}
}


int main()
{
	std::shared_ptr<Library> myLibrary = std::make_shared<Library>();
	myLibrary->AppendBook(std::make_shared<Book>("���� ���� �̷�", 25000));
	myLibrary->AppendBook(std::make_shared<Book>("��Ʈ��ũ �̷�", 30000));
	myLibrary->AppendBook(std::make_shared<Book>("�׷��Ƚ�", 35000));
	myLibrary->AppendBook(std::make_shared<Book>("�˰��� �� �ڷᱸ��", 33000));
	myLibrary->PrintBookInfo();


	std::shared_ptr<Book> book01 = myLibrary->GetIndex()[0];
	Book::BookBuilder builder;
	book01 = std::make_shared<Book>(builder
		.SetName("������ �Ǵ� å")
		.SetPrice(2000)
		.Build());

	std::shared_ptr<Book> book02 = book01;
	
	
	book01->GetInfo();

	std::cout << book01.unique() << std::endl;
	book02.reset();
	std::cout << book01.unique() << std::endl;
	book01.reset();
	/*
	shared_ptr�� RAII�̸�, shared ownership�̴�.
	���� unique_ptr�� �ٸ��� �������� ������ �� �ִ�.
	shared_ptr���� use_count() �� ���ؼ� ���� ������ Ƚ���� �� �� �ִµ�
	�ٸ� �����ٰ� ������ �� ������ count�� 1�� ������ �Ǹ�,
	������ scope�� �������� �����Ǵ� unique_ptr�� �ٸ���
	���� Ƚ�� (use_count())�� 0�� �ɶ� �ڵ����� ������ �ȴ�.

	== ���� ���� ==
	������shared_ptr ������Ʈ�� ���θ� ���ÿ� ����Ű�� �ʵ��� ����� �Ѵٴ� ���� �����ؾ� �Ѵ�.
	*/
	std::cout << book01.use_count() << std::endl;


	
	return 0;
}

