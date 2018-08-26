#include<iostream>
using namespace std;

class Vehicle
{
    public:
        Vehicle();
        ~Vehicle();
        Vehicle(const Vehicle& other);
        Vehicle& operator= (const Vehicle& other);
        Vehicle operator<(const Vehicle& other);

        void setBrand(char const *);
        void setModel(char const *);
        void setSpeed(int speed);
        void setSeats(int seats);

        char* getBrand()const;
        char* getModel()const;
        int getSeats()const;
        int getSpeed()const;

    private:
        char* m_brand;
        char* m_model;
        int m_speed;
        int m_seats;

      friend bool operator < (const Vehicle& lhs, const Vehicle& rhs)
      {
          return lhs.m_speed < rhs.m_speed;
      }
};
