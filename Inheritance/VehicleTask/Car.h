#include "Vehicle.h"

class Car: public Vehicle
{
    public:
        Car();
        ~Car();
        Car(const Car& other);
        Car& operator= (const Car& other);
        Car operator<(const Car& other);

        void setOwner(char const *);
        void setConsumption(int consumption);

        char* getOwner()const;
        int getConsumption()const;

    private:
        char* m_owner; //име на собственика
        int m_consumption; //разход на гориво в литри

};
