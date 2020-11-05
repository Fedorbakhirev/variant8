#ifndef DATE_H
#define DATE_H

#include <string>


using namespace std;
class Date
{
public:
    Date(int year, int month, int day, int hour);
    Date(int year, int month, int day);
    Date();
    int year;
    int month;
    int day;
    int hour;

    bool equals(Date otherDate);
    static bool comp(Date a, Date b);
    wstring toString();
};

#endif // DATE_H
