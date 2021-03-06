#ifndef Included_NameModel_H
#define Included_NameModel_H
#include <iostream>

using namespace std;

class Expression
{
public:
	Expression();

	virtual double value() const = 0;
	virtual void print() const = 0;

	virtual Expression * clone() const = 0;

	virtual void helperPrint() const = 0;

	virtual ~Expression();

private:

};
#endif // Included_NameModel_H

