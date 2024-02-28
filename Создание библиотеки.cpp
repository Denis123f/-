#include <vector>
#include <iostream>
#include <string>


using namespace std;

/*—оздать класс "Ѕиблиотека", который содержит список книг, 
список читателей и методы дл€ добавлени€ книги в библиотеку, 
выдачи книги читателю, возврата книги и отслеживани€ истории выдачи книг.*/

class Library {
	vector<string> books;
	vector<string> users;
	vector<string> usersBook{};
	
	int search(string book)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (book == books[i])
			{
				books.erase(books.begin() + i);
				return 1;
			}
		};
		return 0;
	}

public:

	void insertNewBook(string book) 
	{
		books.push_back(book);
	}

	void outsertBook(string name, string book) 
	{
		if (search(book)) 
		{
			string vremenaya = name + " " + book;
			users.push_back(name);
			usersBook.push_back(vremenaya);
		}
		else
		{
			cout << "Not have a book";
		}
	}
	
	void insertOldBook(string name, string book)
	{
		string vremenaya = name + " " + book;
		if (usersBook.empty() != 1)
		{
			for (int i = 0; i < usersBook.size(); i++)
			{
				if (vremenaya == usersBook[i])
				{
					usersBook.erase(usersBook.begin() + i);
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "Not have a user" << endl;
		}
	}

	void historyBooks() 
	{
		if (usersBook.empty() != 1)
		{
			for (int i = 0; i < usersBook.size(); i++)
			{
				cout << "\nhave a book: " << usersBook[i] << endl;
			}
			cout << "-------------------------------------------" << endl;
		}
		
		for (int i = 0; i < books.size(); i++)
		{
			
			cout << "\nfree a book: " << books[i] <<  endl;
		}
	};
};



int main() {
	Library denis;

	

	denis.insertNewBook("harr");
	denis.insertNewBook("wolf");
	denis.insertNewBook("zeus");
	denis.insertNewBook("like");
	denis.insertNewBook("swwitb");
	denis.insertNewBook("jh");

	denis.historyBooks();

	denis.outsertBook("any", "like");
	denis.outsertBook("denis", "zeus");

	denis.historyBooks();

	denis.insertOldBook("denis", "zeus");

	denis.historyBooks();

	return 0;	
}