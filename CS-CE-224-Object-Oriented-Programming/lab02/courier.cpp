#include<iostream>
using namespace std;

int main(){
    char service;
    int cargo;
    cout << "Service: ";
    cin >> service;
    cout << "Cargo: ";
    cin >> cargo;
    int north[10] = {500, 900,1600,300,600,1100,200,450,800};
    int central[10] = {550, 950,1700,320,620,1150,220,470,850};
    int southern[10] = {600, 1000,1800,350,650,1200,250,500,900};

    switch(service){
        case 'U':
        switch(cargo){
            case 1:
            cout << "Category: Urgent Service, Documents \n";
            cout << "Prices: "<< north[(0*3)+0] << ", " << central[(0*3)+0] << ", " << southern[(0*3)+0] <<endl ;
            cout << "Average Price: " << (float(north[(0*3)+0] + central[(0*3)+0] + southern[(0*3)+0])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(0*3)+0] << " PKR \n";
            cout << "Minimum Price: " << north[(0*3)+0] << " PKR \n";
            break;
            case 2 : 
            cout << "Category: Urgent Service, Parcel < 5kg \n";
            cout << "Prices: "<< north[(0*3)+1] << ", " << central[(0*3)+1] << ", " << southern[(0*3)+1] <<endl ;
            cout << "Average Price: " << (float(north[(0*3)+1] + central[(0*3)+1] + southern[(0*3)+1])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(0*3)+1] << " PKR \n";
            cout << "Minimum Price: " << north[(0*3)+1] << " PKR \n";
            break;
            case 3 : 
            cout << "Category: Urgent Service, Parcel >= 5kg \n";
            cout << "Prices: "<< north[(0*3)+2] << ", " << central[(0*3)+2] << ", " << southern[(0*3)+2] <<endl ;
            cout << "Average Price: " << (float(north[(0*3)+2] + central[(0*3)+2] + southern[(0*3)+2])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(0*3)+2] << " PKR \n";
            cout << "Minimum Price: " << north[(0*3)+2] << " PKR \n";
            break;}
        break;
        case 'N':
        switch(cargo){
            case 1:
            cout << "Category: Normal Service, Documents \n";
            cout << "Prices: "<< north[(1*3)+0] << ", " << central[(1*3)+0] << ", " << southern[(1*3)+0] <<endl ;
            cout << "Average Price: " << (float(north[(1*3)+0] + central[(1*3)+0] + southern[(1*3)+0])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(1*3)+0] << " PKR \n";
            cout << "Minimum Price: " << north[(1*3)+0] << " PKR \n";
            break;
            case 2 : 
            cout << "Category: Normal Service, Parcel < 5kg \n";
            cout << "Prices: "<< north[(1*3)+1] << ", " << central[(1*3)+1] << ", " << southern[(1*3)+1] <<endl ;
            cout << "Average Price: " << (float(north[(1*3)+1] + central[(1*3)+1] + southern[(1*3)+1])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(1*3)+1] << " PKR \n";
            cout << "Minimum Price: " << north[(1*3)+1] << " PKR \n";
            break;
            case 3 : 
            cout << "Category: Normal Service, Parcel >= 5kg \n";
            cout << "Prices: "<< north[(1*3)+2] << ", " << central[(1*3)+2] << ", " << southern[(1*3)+2] <<endl ;
            cout << "Average Price: " << (float(north[(1*3)+2] + central[(1*3)+2] + southern[(1*3)+2])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(1*3)+2] << " PKR \n";
            cout << "Minimum Price: " << north[(1*3)+2] << " PKR \n";
            break;}
        break;
        case 'E':
        switch(cargo){
            case 1:
            cout << "Category: Economy Service, Documents \n";
            cout << "Prices: "<< north[(2*3)+0] << ", " << central[(2*3)+0] << ", " << southern[(2*3)+0] <<endl ;
            cout << "Average Price: " << (float(north[(2*3)+0] + central[(2*3)+0] + southern[(2*3)+0])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(2*3)+0] << " PKR \n";
            cout << "Minimum Price: " << north[(2*3)+0] << " PKR \n";
            break;
            case 2 : 
            cout << "Category: Economy Service, Parcel < 5kg \n";
            cout << "Prices: "<< north[(2*3)+1] << ", " << central[(2*3)+1] << ", " << southern[(2*3)+1] <<endl ;
            cout << "Average Price: " << (float(north[(2*3)+1] + central[(2*3)+1] + southern[(2*3)+1])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(2*3)+1] << " PKR \n";
            cout << "Minimum Price: " << north[(2*3)+1] << " PKR \n";
            break;
            case 3 : 
            cout << "Category: Economy Service, Parcel >= 5kg \n";
            cout << "Prices: "<< north[(2*3)+2] << ", " << central[(2*3)+2] << ", " << southern[(2*3)+2] <<endl ;
            cout << "Average Price: " << (float(north[(2*3)+2] + central[(2*3)+2] + southern[(2*3)+2])/3) << " PKR \n";
            cout << "Maximum Price: " << southern[(2*3)+2] << " PKR \n";
            cout << "Minimum Price: " << north[(2*3)+2] << " PKR \n";
            break;}
    }
    return 0;
}
