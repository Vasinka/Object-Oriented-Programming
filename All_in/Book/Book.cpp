#include "Book.h"

Book::Book() : title(NULL)
{
	setTitle("");
	setPagesCount(0);
}

Book::Book(const char *t, int n) : title(NULL)
{
	setTitle(t);
	setPagesCount(n);
}

Book::~Book()
{
	delete[] title;
}

Book::Book(const Book &b) : title(NULL)
{
	setTitle(b.title);
	setPagesCount(b.pagesCount);
}

Book & Book::operator=(const Book &b)
{
	if (this == &b)
	{
		return *this;
	}
	setTitle(b.title);
	setPagesCount(b.pagesCount);
	return *this;
}

void Book::setTitle(const char *t)
{
	if (t == NULL)
	{
		title = new char[1];
		strcpy(title, "");
	}
	else
	{
		if (title != NULL)
		{
			delete[] title;
		}
		char* newTitle = new char[strlen(t) + 1];
		strcpy(newTitle, t);
		title = newTitle;
	}
}

void Book::setPagesCount(int n)
{
	pagesCount = n;
}

const char * Book::getTitle() const
{
	return title;
}

int Book::getPagesCount() const
{
	return pagesCount;
}

void Book::print() const
{
	std::cout << title << std::endl << pagesCount << std::endl;
}

std::ostream & operator<<(std::ostream &strm, const Book &b)
{
	strm << b.title << std::endl << b.pagesCount << std::endl;
	return strm;
}

std::istream & operator>>(std::istream &strm, Book &b)
{
	int capacity = 10;
	int currIndex = 0;
	char* str = new char[capacity];
	char currChar = strm.get();
	while (currChar != '\n')
	{
		if (currIndex == capacity)
		{
			capacity *= 2;
			char* tmp = new char[capacity];
			strcpy(tmp, str);
			delete[] str;
			str = tmp;
		}
		str[currIndex] = currChar;
		currChar = strm.get();
		currIndex++;
	}
	str[currIndex] = '\0';
	b.setTitle(str);

	int newPagesCount;
	strm >> newPagesCount;
	b.setPagesCount(newPagesCount);

	return strm;
}

bool operator>(const Book &b1, const Book &b2)
{
	if (strcmp(b1.title, b2.title) > 0)
	{
		return true;
	}
	return false;
}

bool operator<(const Book &b1, const Book &b2)
{
	if (strcmp(b1.title, b2.title) < 0)
	{
		return true;
	}
	return false;
}
