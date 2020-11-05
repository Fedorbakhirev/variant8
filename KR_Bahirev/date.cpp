#include "date.h"

Date::Date(int year, int month, int day, int hour)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = 0;
}

Date::Date()
{
    this->year = 0;
    this->month = 0;
    this->day = 0;
    this->hour = 0;
}

bool Date::equals(Date otherDate)
{
    return year == otherDate.year && month == otherDate.month &&
        day == otherDate.day && hour == otherDate.hour;
}

bool Date::comp(Date a, Date b)
{
    return (a.year < b.year) ||
        (a.year == b.year && a.month < b.month) ||
        (a.year == b.year && a.month == b.month && a.day < b.day) ||
        (a.year == b.year && a.month == b.month && a.day == b.day && a.hour < b.hour);
}

wstring Date::toString()
{
    return to_wstring(day) + L"/" + to_wstring(month) + L"/" + to_wstring(year) + L" " + to_wstring(hour) + L"-" + to_wstring(hour + 1);
}
