//#include "Vehicle.h"
#include "Car.h"

int main ()
{
    Vehicle kola1;
    kola1.setBrand("Volkswagen");
    kola1.setModel("T-ROC");
    kola1.setSeats(5);
    kola1.setSpeed(260);

    cout<<kola1.getBrand()<<endl;
    cout<<kola1.getModel()<<endl;
    cout<<kola1.getSeats()<<endl;
    cout<<kola1.getSpeed()<<endl;

    Car kola2;
    kola2.setBrand("Volkswagen");
    kola2.setModel("CC");
    kola2.setSeats(5);
    kola2.setSpeed(200);
    kola2.setOwner("Bastian");
    kola2.setConsumption(6);

    cout<<kola2.getBrand()<<endl;
    cout<<kola2.getModel()<<endl;
    cout<<kola2.getSeats()<<endl;
    cout<<kola2.getSpeed()<<endl;
    cout<<kola2.getOwner()<<endl;
    cout<<kola2.getConsumption()<<endl;


}
