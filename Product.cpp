#include "Product.h"
#include<cstring>

Product::Product() : name(NULL)
{
	name = new char[1];
	strcpy(name, "");
	number = 100000;
	price = 0.0;
}

Product::Product(char * nam, unsigned long num, double p) : name(NULL)
{
	setName(nam);
	setNumber(num);
	setPrice(p);
}

Product::~Product()
{
	delete[] name;
}

Product::Product(const Product & p) : name(NULL)
{
	setName(p.name);
	setNumber(p.number);
	setPrice(p.price);
}

Product & Product::operator=(const Product & p)
{
	if (this == &p)
	{
		return *this;
	}
	setName(p.name);
	setNumber(p.number);
	setPrice(p.price);
	return *this;
}

char * Product::getName() const
{
	return name;
}

unsigned long Product::getNumber() const
{
	return number;
}

double Product::getPrice() const
{
	return price;
}

void Product::setName(const char * n)
{
	if (n == NULL)
	{
		name = new char[1];
		strcpy(name, "");
	}
	else
	{
		if (name != NULL)
		{
			delete[] name;
		}
		char* newName = new char[strlen(n) + 1];
		strcpy(newName, n);
		name = newName;
	}
}

void Product::setNumber(unsigned long n)
{
	if (n > 99999 && n < 1000000)
	{
		number = n;
	}
	else
	{
		throw "invalid input data for number";
	}
}

void Product::setPrice(double p)
{
	price = p;
}

std::ostream & operator<<(std::ostream & strm, const Product & p)
{
	strm << p.getName() << std::endl << p.getNumber() << std::endl << p.getPrice() << std::endl;
	return strm;
}

std::istream & operator>>(std::istream & strm, Product & p)
{
	char* name = new char[100];
	strm >> name;
	p.setName(name);
	unsigned long number;
	strm >> number;
	p.setNumber(number);
	double price;
	strm >> price;
	p.setPrice(price);
	return strm;
}

