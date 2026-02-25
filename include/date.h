#ifndef DATE_H
#define DATE_H

#include<stdexcept>
class Date{
    public:
        Date(int d, int m, int y);
        ~Date();

        int getDay(){return Day;}
        int getMonth(){return Month;}
        int getYear(){return Year;}

        void setDay(int d){Day = d;}
        void setMonth(int m){Month = m;}
        void setYear(int y){Year = y;}
        bool IsOnOrAfter(Date date);
        bool isEmpty(){return Day == 0 && Month == 0 && Year == 0;}
    protected:
        int Day, Month, Year;
};

#endif