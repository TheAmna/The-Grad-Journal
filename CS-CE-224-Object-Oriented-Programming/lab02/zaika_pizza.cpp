#include<iostream>
#include <cmath>
using namespace std;

int main(){
    char flavor1, flavor2;
    char size1, size2;
    int day,total;
    cout << "Enter day of week: " ;
    cin >> day;
    cout << "Enter first pizza flavor (c/b/v/p/a): " ;
    cin >> flavor1;
    cout << "Enter first pizza size (s/m/l): " ;
    cin >> size1;
    cout << "Enter second pizza flavor (c/b/v/p/a): " ;
    cin >> flavor2;
    cout << "Enter second pizza size (s/m/l): " ;
    cin >> size2;
    cout << "You ordered: \n";
    total = 0;

    switch(flavor1){

        case 'c':
        switch(size1){
            case 's':
            cout << "- Small Chicken Pizza: 800 PKR \n";
            total += 800;
            break;
            case 'm':
            cout << "- Medium Chicken Pizza: 1000 PKR\n";
            total += 1000;
            break;
            case 'l':
            cout << "- Large Chicken Pizza: 1200 PKR\n";
            total += 1200;
            break;}
        break;
        case 'b':
        switch(size1){
            case 's':
            cout << "- Small Beef Pizza: 900 PKR\n";
            total += 900;
            break;
            case 'm':
            cout << "- Medium  Beef Pizza: 1100 PKR\n";
            total += 1100;
            break;
            case 'l':
            cout << "- Large  Beef Pizza: 1300 PKR\n";
            total += 1300;
            break;}
        break;
        case 'v':
        switch(size1){
            case 's':
            cout << "- Small Vegetarian Pizza: 700 PKR\n";
            total += 700;
            break;
            case 'm':
            cout << "- Medium  Vegetarian Pizza: 900 PKR\n";
            total += 900;
            break;
            case 'l':
            cout << "- Large  Vegetarian Pizza: 1100 PKR\n";
            total += 1100;
            break;}
        break;
        case 'p':
        switch(size1){
            case 's':
            cout << "- Small Plain Pizza: 600 PKR\n";
            total += 600;
            break;
            case 'm':
            cout << "- Medium  Plain Pizza: 800 PKR\n";
            total += 800;
            break;
            case 'l':
            cout << "- Large  Plain Pizza: 1000 PKR\n";
            total += 1000;
            break;}
        break;
        case 'a':
        switch(size1){
            case 's':
            cout << "- Small Assorted Pizza: 1000 PKR\n";
            total += 1000;
            break;
            case 'm':
            cout << "- Medium  Assorted Pizza: 1200 PKR\n";
            total += 1200;
            break;
            case 'l':
            cout << "- Large  Assorted Pizza: 1400 PKR\n";
            total += 1400;
            break;}
        break;}

    switch(flavor2){
        case 'c':
        switch(size2){
            case 's':
            cout << "- Small Chicken Pizza: 800 PKR\n";
            total += 800;
            break;
            case 'm':
            cout << "- Medium Chicken Pizza: 1000 PKR\n";
            total += 1000;
            break;
            case 'l':
            cout << "- Large Chicken Pizza: 1200 PKR\n";
            total += 1200;
            break;}
        break;    
        case 'b':
        switch(size2){
            case 's':
            cout << "- Small Beef Pizza: 900 PKR\n";
            total +=900;
            break;
            case 'm':
            cout << "- Medium  Beef Pizza: 1100 PKR\n";
            total += 1100;
            break;
            case 'l':
            cout << "- Large  Beef Pizza: 1300 PKR\n";
            total += 1300;
            break;}
        break;

        case 'v':
        switch(size2){
            case 's':
            cout << "- Small Vegetarian Pizza: 700 PKR\n";
            total += 700;
            break;
            case 'm':
            cout << "- Medium  Vegetarian Pizza: 900 PKR\n";
            total += 900;
            break;
            case 'l':
            cout << "- Large  Vegetarian Pizza: 1100 PKR\n";
            total += 1100;
            break;}
        break;
        case 'p':
        switch(size2){
            case 's':
            cout << "- Small Plain Pizza: 600 PKR\n";
            total += 600;
            break;
            case 'm':
            cout << "- Medium  Plain Pizza: 800 PKR\n";
            total += 800;
            break;
            case 'l':
            cout << "- Large  Plain Pizza: 1000 PKR\n";
            total += 1000;
            break;}
        break;
        cout << total << endl;
        case 'a':
        switch(size2){
            case 's':
            cout << "- Small Assorted Pizza: 1000 PKR\n";
            total += 1000;
            cout << total << endl;
            break;
            case 'm':
            cout << "- Medium  Assorted Pizza: 1200 PKR\n";
            total += 1200;
            break;
            case 'l':
            cout << "- Large  Assorted Pizza: 1400 PKR\n";
            total += 1400;
            break;
        break;}
    }

    switch(day){
        case 1:
        if (flavor1 == 'c' && size1 =='m' || flavor2 == 'c' && size2 =='m'){
            cout << "Monday Deal Applied : Buy 1 Medium Chicken Pizza , get 1 Small Chicken Pizza free. \n";
        break;}
        case 2:
        if (size1 =='l' || size2 =='l'){
            cout << "Tuesday Deal Applied : Buy 1 Large Pizza, get 1 free ( same flavor and size ). \n";
        break;}
        case 3:
        if (size1 =='s' || size2 =='s' ){
            cout << "Wednesday Deal Applied : Buy 2 Small Pizzas (any flavors), get 20% off. \n";
        break;}
        case 4:
        if (flavor1 =='b' || flavor2 =='b'){
            cout << "Thursday Deal Applied : Buy 1 Beef Pizza of any size, get 1 Small Plain Pizza free. \n";
        break;}
        case 5:
        if (flavor1 == 'a' && size1 =='l' || flavor2 == 'a' && size2 =='l'){
            cout << "Friday Deal Applied : Buy 1 Large Assorted Pizza, get 1 Medium Vegetarian Pizza free.\n";
        break;}
        case 6:
            cout << "Saturday Deal Applied :  No deal.\n";
        break;
        case 7:
        if (size1 =='m' || size2 =='m'){
            cout << "Sunday Deal Applied : Buy 1 Medium Pizza (any flavor), get 1 Small Vegetarian Pizza free.\n";
        }
    }

    if (day == 2){
        cout << "Final Bill: " << (total/2) << " PKR" << endl;
    }
    else if (day == 3){
        cout << "Final Bill: " << (total*0.8) << " PKR" << endl;
    }    
    else 
    { cout << "Final Bill: " << total<< " PKR" << endl;}
    return 0; 
}
