#include<iostream>
#include<cmath>
using namespace std;

class Absolute
{
    public:
    int ab(int); //absolute value of integer number
    double ab (double);
};

int Absolute::ab(int x)
{
    return abs(x);
}

double Absolute::ab(double x)
{
    return fabs(x);
}

int main()
{
    Absolute number;

    cout << number.ab(-5) << endl;

    cout << number.ab(-5.16) << endl;
}
