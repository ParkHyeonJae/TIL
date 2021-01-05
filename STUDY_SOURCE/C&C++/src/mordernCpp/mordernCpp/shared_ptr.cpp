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
		BookBuilder() : name("책1"), price(0) {}

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
	myLibrary->AppendBook(std::make_shared<Book>("게임 개발 이론", 25000));
	myLibrary->AppendBook(std::make_shared<Book>("네트워크 이론", 30000));
	myLibrary->AppendBook(std::make_shared<Book>("그래픽스", 35000));
	myLibrary->AppendBook(std::make_shared<Book>("알고리즘 및 자료구조", 33000));
	myLibrary->PrintBookInfo();


	std::shared_ptr<Book> book01 = myLibrary->GetIndex()[0];
	Book::BookBuilder builder;
	book01 = std::make_shared<Book>(builder
		.SetName("도움이 되는 책")
		.SetPrice(2000)
		.Build());

	std::shared_ptr<Book> book02 = book01;
	
	
	book01->GetInfo();

	std::cout << book01.unique() << std::endl;
	book02.reset();
	std::cout << book01.unique() << std::endl;
	book01.reset();
	/*
	shared_ptr은 RAII이며, shared ownership이다.
	따라서 unique_ptr과 다르게 소유권을 공유할 수 있다.
	shared_ptr에는 use_count() 를 통해서 현재 참조된 횟수를 볼 수 있는데
	다른 곳에다가 참조를 할 때마다 count가 1씩 증가가 되며,
	생성된 scope의 끝지점에 해제되는 unique_ptr과 다르게
	참조 횟수 (use_count())가 0이 될때 자동으로 해제가 된다.

	== 주의 할점 ==
	각각의shared_ptr 오브젝트가 서로를 동시에 가르키지 않도록 해줘야 한다는 점을 주의해야 한다.
	*/
	std::cout << book01.use_count() << std::endl;


	
	return 0;
}

