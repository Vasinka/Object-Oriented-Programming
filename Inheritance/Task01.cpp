//for a better example of inheritance look at Inheritance/VehicleTask
#include<iostream>
#include<cstring>
using namespace std;


class Vehicle {
    char * make;
    char * model;
    char * color;
    int year;
    int mileage;

public:
    Vehicle()
    {

    make = new char[1];
	strcpy(make, "");

	model = new char[1];
	strcpy(model, "");

	color = new char[1];
	strcpy(color, "");

	year = 0;
	mileage = 0;

    }

    Vehlice (char * _make, char* _model, char * _color, int _year, int _mileage)

    {
        delete [] make;
        delete [] model;
        delete [] color;

        set_make(_make);
        set_model(_model);
        set_color(_color);

        set_year(_year);
        set_mileage(_mileage);


    }

   /*Vehicle(const Vehicle& other)
    {

    }
    */

    Vehicle& operator= (const Vehicle& other)
    {
        return *this;
    }

    virtual ~Vehicle()
    {

    delete [] make;
    delete [] model;
    delete [] color;

    }

    char* get_make() const
    {
        return make;
    }
    char* get_model() const
    {
        return model;
    }
    char* get_color() const
    {
        return color;
    }
    int get_year() const
    {
        return year;
    }
    int get_mileage() const
    {
        return mileage;
    }


    void set_make(const char* _make)
    {
        delete [] _make;
        make = new char [strlen(_make)+1];
        strcpy(make, _make);
    }

    void set_model(const char* _model)
    {
        delete [] model;
        model = new char [strlen(_model)+1];
        strcpy(model, _model);
    }

    void set_color(const char* _color)
    {
         delete [] color;
        make = new char [strlen(_color)+1];
        strcpy(color, _color);
    }

    void set_year(int _year)
    {
        year = _year;
    }
    void set_mileage(int _mileage)

    {
        mileage = _mileage;
    }

    virtual void details() const = 0;
};


class Car : public Vehicle
{
public:
    void details() const
    {
        cout << "Make: " << get_make() << endl;
        cout   << "Model: " << get_model() << endl;
        cout  << "Color: " << get_color() << endl;
        cout  << "Year: " << get_year() << endl;
        cout  << "Mileage: " << get_mileage() << endl;
    }
};


class Truck : public Vehicle
{
    int size;
public:
    Truck(): Vehicle()
    {
        size = 0;
    }
    Truck(const Truck& other) : Vehicle(other) {
        size = other.size;
    }
    Truck& operator= (const Truck& other)
    {
        Vehicle::operator=(other);
        size = other.size;
    }

    ~Truck()
    {

    }

    int get_size() const
    {
        return size;
    }
    void set_size(int _size)
    {
        size = _size;

    }

    void details() const
     {
        cout << "Make: " << get_make() << '\n'
            << "Model: " << get_model() << '\n'
            << "Color: " << get_color() << '\n'
            << "Year: " << get_year() << '\n'
            << "Mileage: " << get_mileage() << '\n'
            << "Size: " << size << '\n';
    }
};


class Motorcycle : public Vehicle
 {
    char* type;
public:
    Motorcycle() : Vehicle()
    {
        type = " ";
    }
    Motorcycle(const Motorcycle& other) : Vehicle(other) {
        type = other.type;
    }
    Motorcycle& operator= (const Motorcycle& other) {
        Vehicle::operator=(other);
        type = other.type;
    }
    ~Motorcycle() {
        delete [] type;
    }

    char* get_type() const {
        return type;
    }

    void set_type(const char* _type)
    {
        delete [] type;
        type = new char [strlen(_type)+1];
        strcpy(type, _type);
    }

    void details() const {
        cout << "Make: " << get_make() << '\n'
            << "Model: " << get_model() << '\n'
            << "Color: " << get_color() << '\n'
            << "Year: " << get_year() << '\n'
            << "Mileage: " << get_mileage() << '\n'
            << "Type: " << type << '\n';
    }
};


int main() {
    return 0;
}
