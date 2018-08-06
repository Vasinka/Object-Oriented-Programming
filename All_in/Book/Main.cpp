#include "Library.h"
#include "Ebook.h"

int main()
{
	Book book1("Harry Potter", 560);
	Book book2("Tiutiun", 360);
	Book book3("Winnie the Pooh", 780);

	Library myLibrary(5);

	myLibrary.addBook(book2);
	myLibrary.addBook(book1);
	myLibrary.addBook(book3);

	//myLibrary.removeBook(1);

	//std::cout << myLibrary.getAvaragePageCount() << std::endl;

	Book selectedBook = myLibrary[0];

	myLibrary.sortByTitle();
	myLibrary.print();

	EBook pipi("Pipi Dylgoto Chorapche", 450, 20, 130);
	std::cout << pipi.getRating() << std::endl;
}
