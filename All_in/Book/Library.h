#pragma once
#include "Book.h"

class Library
{
public:
	Library(int);
	~Library();
	double getAvaragePageCount() const;
	void addBook(Book);
	void removeBook(int);
	void print() const;
	Book& operator[] (int) const;
	void sortByTitle();
private:
	Book* books;
	int booksCount;
};
