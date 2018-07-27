/**task: Add 3 functions to the class Point3:
//       1. function that inputs an array of points in the 3D-Dimension
         2. function that changes the coordinates of each point with their symmetrical match respect to (0;0)
         3. function that outputs an array of points in the 3D-Dimension

*/
#include<iostream>
using namespace std;

class Point3
{
    public:

        Point3 (int = 0, int = 0, int = 0); //default constructor

        Point3 (const Point3 &); //copy constructor

        int getX() const;
        int getY() const;
        int getZ() const;

        void setX(int);
        void setY(int);
        void setZ(int);

        void input (int n, Point3 a[]) //task 1
        {
            for (int i = 0; i < n; i++)
            {
                int p;

                cout << " x= ";
                cin>>p;
                a[i].setX(p);

                cout << " y= ";
                cin>>p;
                a[i].setY(p);

                cout << " z= ";
                cin>>p;
                a[i].setZ(p);
            }
        }

    private:

        int m_x;
        int m_y;
        int m_z;
};

Point3::Point3(int x, int y, int z)
{
    m_x = x;
    m_y = y;
    m_z = z;
};

Point3::Point3 (const Point3& p)
{
    m_x = p.m_x;

    m_y = p.m_y;

    m_z = p.m_z;
}

int Point3::getX()const
{
    return m_x;
}

int Point3::getY()const
{
    return m_y;
}

int Point3::getZ()const
{
    return m_z;
}

void Point3::setX(int x)
{
    m_x = x;
}

void Point3::setY(int y)
{
    m_y = y;
}

void Point3::setZ(int z)
{
    m_z = z;
}

int main ()
{
    Point3 P1;

    //expected result: 0 0 0 (the values from the default constructor)
    cout << P1.getX() << " " << P1.getY() << " " << P1.getZ() << endl;

    Point3 P2(1,1,1);

    cout << P2.getX() << " " << P2.getY() << " " << P2.getZ() << endl;

    Point3 P3 = P2; //using the copy constructor

    cout << P3.getX() << " " << P3.getY() << " " << P3.getZ() << endl;

    //changing the coordinates of P3
    P3.setX(4);
    P3.setY(12);
    P3.setZ(18);

    cout << P3.getX() << " " << P3.getY() << " " << P3.getZ() << endl;

    return 0;
}
