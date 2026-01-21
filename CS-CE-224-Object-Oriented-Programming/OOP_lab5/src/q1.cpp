#include<iostream>
using namespace std;

class TollBooth{
    private:
        unsigned int total_cars;
        unsigned int total_amount;

    public:
        TollBooth() : total_cars(0), total_amount(0) //ctor
        {}
        void payingCar(){
            total_cars++;
            total_amount += 50;
        }
        void nopayCar(){
            total_cars++;
        }
        unsigned int display(){
            cout << "Total cars: " << total_cars << endl;
            cout << "Total toll collected: Rs. " << total_amount << endl;
        }
};

int main(){
    char letter;
    bool flag = true;
    TollBooth car;

    while (flag){
        cout << "Please enter \'p\' if paying car passed, \'n\' for non-paying car, and \'q\' for termination: ";
        cin >> letter;
        if (letter == 'q'){
            flag = false;
          
        }
        else if (letter == 'p'){
            car.payingCar();
        }
        else if (letter =='n'){
            car.nopayCar();
        }
        else {cout << "Invalid input ! ";}
    }
    car.display();
    return 0;
}