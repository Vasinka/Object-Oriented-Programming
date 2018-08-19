#include<iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

class BaseEllipse 
{
    public:
	    BaseEllipse(double x0 = 0, double y0 = 0);
	    virtual ~BaseEllipse() {}
	    virtual double Area() const = 0; // a pure virtual function; it makes the class abstract

    private:
	  Point center;
};

