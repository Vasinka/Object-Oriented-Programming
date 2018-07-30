#include<iostream>
using namespace std;

class Fraction
{

    public:

        Fraction (int nom, int denom)
        {
            m_nom = nom;
            m_denom = denom;
        }

        int getNom () const
        {
            return m_nom;
        }

        int getDenom () const
        {
            return m_denom;
        }

        friend bool isFraction (const Fraction& obj)
        {
            return obj.m_nom % obj.m_denom !=0;
        }

    private:

        int m_nom;
        int m_denom;

};

int main ()
{
    Fraction myFraction(5,12);

    if (isFraction(myFraction))
    {
        cout << myFraction.getNom() << " " << myFraction.getDenom() << endl;
    }

    else
    {
        cout << myFraction.getNom() << "is dividible by" << myFraction.getDenom() << endl;
    }

    return 0;
}
