#include "EBook.h"

EBook::EBook(char * t, int pageCount, int s, int o) : Book(t, pageCount)
{
	setSizeInBytes(s);
	setOpeningCount(o);
}

int EBook::getSizeInBytes() const
{
	return sizeInBytes;
}

int EBook::getOpeningCount() const
{
	return openingCount;
}

void EBook::setSizeInBytes(int s)
{
	sizeInBytes = s;
}

void EBook::setOpeningCount(int c)
{
	openingCount = c;
}

double EBook::getRating() const
{
	if (openingCount > 200)
	{
		return 5;
	}
	else
	{
		return (double)openingCount / 40;
	}
}
