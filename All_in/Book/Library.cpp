#include "Library.h"

Library::Library(int n) : books(NULL)
{
	books = new Book[n];
	booksCount = 0;
}

Library::~Library()
{
	delete[] books;
}

double Library::getAvaragePageCount() const
{
	double pageSum = 0;
	for (size_t i = 0; i < booksCount; i++)
	{
		pageSum += books[i].getPagesCount();
	}

	return pageSum / booksCount;
}

void Library::addBook(Book b)
{
	books[booksCount] = b;
	booksCount++;
}

void Library::removeBook(int indexToRemove)
{
	Book* newBooks = new Book[booksCount - 1];
	for (size_t i = 0; i < indexToRemove; i++)
	{
		newBooks[i] = books[i];
	}

	for (size_t i = indexToRemove; i < booksCount - 1; i++)
	{
		newBooks[i] = books[i + 1];
	}

	delete[] books;
	books = newBooks;
	booksCount--;
}

void Library::print() const
{
	for (int i = 0; i < booksCount; i++)
	{
		std::cout << books[i];
	}
}

Book & Library::operator[](int index) const
{
	return books[index];
}

void Library::sortByTitle()
{
	Book temp;
	for (int i = 1; i < booksCount; i++)
	{
		for (int j = 0; j < (booksCount - i); j++)
			if (books[j] > books[j + 1])
			{
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
	}
}
