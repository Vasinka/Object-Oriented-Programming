#include<iostream>
using namespace std;

class Employee
{
    public:
        void read();
        void print () const;

    private:
        struct
        {
            char firstName[16];
            char lastName[16];

        }
        name;

        struct
        {
            double hours; //working hours
            double salary; //salary per hour
        }
        work;
};

void Employee::read()
{
    cout << "First name:";
    cin >> name.firstName;

    cout << "Last name:";
    cin >> name.lastName;

    cout << "Working hours:";
    cin >> work.hours;

    cout << "Salary per hour:";
    cin >> work.salary;

    cin.ignore (); //
}

void Employee::print() const
{
    cout << name.firstName << " " << name.lastName << " " << work.hours * work.salary << endl;
}

int main ()
{
    Employee myEmployee;

    myEmployee.read();

    myEmployee.print();

    return 0;
}
