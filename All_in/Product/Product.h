#pragma once
#include <iostream>
#include <fstream>

class Product
{
public:
	Product();
	Product(char*, unsigned long, double);
	~Product();
	Product(const Product&);
	Product& operator=(const Product&);
	char* getName() const;
	unsigned long getNumber() const;
	double getPrice() const;
	void setName(const char*);
	void setNumber(unsigned long);
	void setPrice(double);

	friend std::ostream& operator<<(std::ostream&, const Product&);
	friend std::istream& operator>>(std::istream&, Product&);
private:
	char* name;
	unsigned long number;
	double price;
};
