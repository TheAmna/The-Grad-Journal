#include<iostream>
using namespace std;

void convert24(int seconds){
    int hours = 0, mins = 0, secs = 0 ;
    mins = seconds / 60;
    secs = seconds % 60;
    hours = mins/60;
    mins = mins%60;

    if (hours > 23) {
        int balance_hour = hours / 24;
        hours = hours % 24;
        cout << "+" << balance_hour << ", ";
    }

    if (hours < 10){
        cout << "0" << hours << ":";
    }
    else {cout << hours<< ":";}

    if (mins < 10){
        cout << "0" << mins << ":";
    }
    else {cout << mins<< ":";}

    if (secs < 10){
        cout << "0" << secs;
    }
    else {cout << secs ;}
}

void convert24(int minutes ,int seconds){
    int mins = (minutes*60) + seconds;
    convert24(mins); 
}

void convert24(int Hours , int minutes ,int seconds){
    int total_secs = Hours * 3600 + minutes * 60 + seconds;
    int hours = 0, mins = 0, secs = 0;
    mins = total_secs / 60;
    secs = total_secs % 60;
    hours = mins / 60;
    mins = mins % 60;

    if (hours > 23) {
        int balance_hour = hours / 24;
        hours = hours % 24;
        cout << "+" << balance_hour << ", ";
    }

    if (hours < 10){
        cout << "0" << hours << ":";
    }
    else {cout << hours<< ":";}

    if (mins < 10){
        cout << "0" << mins << ":";
    }
    else {cout << mins<< ":";}

    if (secs < 10){
        cout << "0" << secs;
    }
    else {cout << secs ;}
    
}

int main(){
    int hours, mins, secs;
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> mins;
    cout << "Enter seconds: ";
    cin >> secs;

    if (hours == 0 && mins == 0) {
        convert24(secs);
    } else if (hours == 0) {
        convert24(mins, secs);
    } else {
        convert24(hours, mins, secs);
    }
    
}