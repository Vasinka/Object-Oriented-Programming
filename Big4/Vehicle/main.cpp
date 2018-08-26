#include "Vehicle.h"

int main ()
{
    Vehicle kola;
    kola.setBrand("Volkswagen");
    kola.setModel("T-ROC");
    kola.setSeats(5);
    kola.setSpeed(260);

    cout<<kola.getBrand()<<endl;
    cout<<kola.getModel()<<endl;
    cout<<kola.getSeats()<<endl;
    cout<<kola.getSpeed()<<endl;

}
