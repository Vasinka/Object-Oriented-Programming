#pragma once
#include "Book.h"
class EBook : public Book
{
public:
	EBook(char*, int, int, int);
	int getSizeInBytes() const;
	int getOpeningCount() const;
	void setSizeInBytes(int);
	void setOpeningCount(int);
	double getRating() const;
private:
	int sizeInBytes;
	int openingCount;
};

