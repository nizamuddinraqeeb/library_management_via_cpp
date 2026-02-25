#include "../include/date.h"

Date::Date(int d, int m, int y) {
    setDay(d);
    setMonth(m);
    setYear(y);
}
Date::~Date() {}

bool Date::IsOnOrAfter(Date date){
    if (Year > date.Year) return true;
    if (Year < date.Year) return false;
    if (Month > date.Month) return true;
    if (Month < date.Month) return false;
    if (Day > date.Day) return true;
    return false;
}