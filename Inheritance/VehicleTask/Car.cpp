#include"Car.h"
#include<cstring>

Car::Car() : Vehicle(), m_consumption(0), m_owner(NULL)
{

}

Car::~Car()
{
    delete [] m_owner;
}

void Car::setOwner(const char* owner)
{
    delete [] m_owner;
    m_owner = new char[strlen(owner)+1];
    strcpy(m_owner, owner);
}

void Car::setConsumption(int consumption)
{
    m_consumption = consumption;
}

char* Car::getOwner()const
{
    return m_owner;
}

int Car::getConsumption()const
{
    return m_consumption;
}

Car & Car::operator=(const Car& other)
{
	if (this != &other)
	{
		Car::operator=(other);
		this->setConsumption(other.m_consumption);
		this->setOwner(other.m_owner);
	}

	return *this;
}

Car::Car(const Car&other):Vehicle()
{
    this->setConsumption(other.m_consumption);
    this->setOwner(other.m_owner);
}
