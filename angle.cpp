#include<iostream>
#include <cmath> //to use the trigonometrical functions sin, cos, tan
using namespace std;

const double DEG_TO_RAD = 3.14159265/180;

class Angle
{
    public:

        //setter to initialize degrees
        void setDegrees(double);

        //getters to find the values of the trigonometrical functions
        double getSin() const;
        double getCos() const;
        double getTan() const;

    private:

        //the only member-value we need
        //in order to find the values of the trigonometrical functions sin, cos, tan
        double m_degrees;

};

void Angle::setDegrees(double degrees)
{
    m_degrees = degrees;
}

double Angle::getSin() const
{
    return sin (DEG_TO_RAD * m_degrees);
}

double Angle::getCos() const
{
    return cos (DEG_TO_RAD * m_degrees);
}

double Angle::getTan() const
{
    return tan (DEG_TO_RAD * m_degrees);
}

int main()
{
    Angle myAngle;

    myAngle.setDegrees(30);

    cout<<myAngle.getSin()<<endl;
    cout<<myAngle.getCos()<<endl;
    cout<<myAngle.getTan()<<endl;


}
