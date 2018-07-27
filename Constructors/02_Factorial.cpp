//TODO: validations
#include<iostream>
using namespace std;

class Factorial
{
    public:

        Factorial (int num) //parametrized constructor
        {
            m_num = num;
        }

        unsigned int value() const //member-function to find the value of m_num!

        {
            if (m_num == 1)
            {
                return 1;
            }

            else
            {
                Factorial t(m_num-1);
                return m_num*t.value();
            }
        }

    private:
        int m_num;
};

int main ()
{
    int num;

    cin >> num;

    Factorial t(num);

    cout << t.value() << endl;

    return 0;
}
