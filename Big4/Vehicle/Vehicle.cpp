#include "Vehicle.h"
#include<cstring>

void Vehicle::setBrand(const char* brand)
{
    delete [] m_brand;
    m_brand = new char[strlen(brand)+1];
    strcpy(m_brand, brand);
}

void Vehicle::setModel(const char* model)
{
    delete [] m_model;
    m_model = new char[strlen(model)+1];
    strcpy(m_model, model);
}

void Vehicle::setSpeed(int speed)
{
    m_speed = speed;
}

void Vehicle::setSeats(int seats)
{
    m_seats = seats;
}

char* Vehicle::getBrand()const
{
    return m_brand;
}

char* Vehicle::getModel()const
{
    return m_model;
}

int Vehicle::getSpeed()const
{
    return m_speed;
}
int Vehicle::getSeats()const
{
    return m_seats;
}
Vehicle::Vehicle()
{
    m_brand = new char[1];
    m_brand[0] = '\0';

   m_model = new char[1];
   m_model[0] = '\0';

   m_speed = 1;
   m_seats = 1;

}

Vehicle::~Vehicle()
{
    delete [] m_brand;
    delete [] m_model;
}

Vehicle::Vehicle(const Vehicle&other)
{
 this->setBrand(other.m_brand);
 this->setModel(other.m_model);
 this->setSpeed(other.m_speed);
 this->setSeats(other.m_seats);
}

Vehicle& Vehicle::operator=(const Vehicle&other)
{
    if (this!=&other)
    {
        this->setBrand(other.m_brand);
        this->setModel(other.m_model);
        this->setSpeed(other.m_speed);
        this->setSeats(other.m_seats);
    }

    return *this;
}
