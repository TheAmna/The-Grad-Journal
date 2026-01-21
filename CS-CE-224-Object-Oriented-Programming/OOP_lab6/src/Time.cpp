#include "Time.hpp"
#include<iostream>
using namespace std;

Time::Time(const int seconds){

    int totalSeconds = seconds % (24 * 60 *60);   // (24*60*60) GIVES THE TOTAL SECONDS IN THE DAY
   
    m_hours  = totalSeconds / 3600;
    m_minutes = (totalSeconds % 3600) /60;
    m_seconds = (totalSeconds % 3600) % 60;
}

Time::Time(const int hours, const int minutes, const int seconds){
    m_hours = hours % 24;
    m_minutes = minutes;
    m_seconds = seconds;
}

// Time(1, 20, 30) + 3045 -> Time(2, 11, 15)
Time Time::operator+(const Time& other) const{
    int hrs, mins, secs;
    secs =  m_seconds + other.m_seconds;
    mins = m_minutes + other.m_minutes;
    hrs = m_hours + other.m_hours;
    secs = (hrs*3600) + (mins*60) + secs;
    Time t1(secs);
    return t1;
   
}

// Time(1, 20, 30) + 3045 -> Time(2, 11, 15)
Time Time::operator+(const int other) const{
    int secs;
    secs = (m_hours*3600) + (m_minutes*60) + m_seconds;
    secs += other;
    Time t1(secs);
    return t1;
}
// // Time(2, 10, 0) - Time(1, 50, 0) -> 00:20:00
Time Time::operator-(const Time& other) const{
    int hrs, mins, secs;
    secs =  m_seconds - other.m_seconds;
    mins = m_minutes - other.m_minutes;
    hrs = m_hours - other.m_hours;

    if (secs > 59){
        secs = secs % 60;
        mins -= secs/60;
    }
    if (mins > 59){
        mins = mins% 60;
        hrs -= mins/60;
    }
    Time t1(hrs,mins,secs);
    return t1;
}

Time Time::operator-(const int other) const{
    int secs;
    secs = (m_hours*3600) + (m_minutes*60) + m_seconds;
    secs -= other;
    Time t1(secs);
    return t1;
}


bool Time::operator==(const Time& other) const{
    if ((m_hours == other.m_hours) & (m_minutes==other.m_minutes) & (m_seconds==other.m_seconds)){
        return true;
        }
    return false;
}

bool Time::operator==(const int other) const{
    int secs;
    secs = (m_hours* 3600) + (m_minutes*60)+ (m_seconds);
    if (secs == other){
        return true;
    } 
    return false;
    }

bool Time::operator!=(const Time& other) const{
    if ((m_hours == other.m_hours) & (m_minutes==other.m_minutes) & (m_seconds==other.m_seconds)){
        return false;
        }
    return true;
    }


bool Time::operator!=(const int other) const{
    int secs;
    secs = (m_hours* 3600) + (m_minutes*60)+ (m_seconds);
    if (secs == other){
        return false;
    } 
    return true;
    }
  
bool Time::operator<(const Time& other) const{
    int time1, time2;
    time1 = (m_hours)*3600 + (m_minutes)*60 + m_seconds;
    time2 = (other.m_hours) *3600 +(other.m_minutes) * 60 + other.m_seconds;
    if (time1< time2){
        return true;
    }
    return false;
}

bool Time::operator<(const int other) const{
    int t1, t2;
    t1 = (m_hours)*3600 + m_minutes *60 + m_seconds;
    if (t1 < other){
        return true;
    }
    return false;
}

bool Time::operator>(const Time& other) const{
    int time1, time2;
    time1 = (m_hours)*3600 + (m_minutes)*60 + m_seconds;
    time2 = (other.m_hours) *3600 +(other.m_minutes) * 60 + other.m_seconds;
    if (time1> time2){
        return true;
    }
    return false;
}


bool Time::operator>(const int other) const{
    int t1, t2;
    t1 = (m_hours)*3600 + m_minutes *60 + m_seconds;
    if (t1 > other){
        return true;
    }
    return false;
}

void Time::show() const{
    cout << "Hours : " << m_hours;
    cout << "Minutes : " << m_minutes;
    cout << "Seconds : " << m_seconds;
}

int Time::getHours() const{
    return m_hours; 
}

int Time::getMinutes() const{
    return m_minutes;

}
int Time::getSeconds() const{
    return m_seconds;
}
