//
// Created by manout on 18-2-26.
//

#include "Date.h"
Date Date::operator+(int d)
{
    Date ans(*this);
    
    while (d not_eq 0)
    {
        int rest;
        int leap;
        switch (ans.month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                rest = 31 - ans.day;
                if (d > rest)
                {
                    d -= 31;
                    ans.month += 1;
                }else
                {
                    ans.day += d;
                    d = 0;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                rest = 30 - ans.day;
                if (d > rest)
                {
                    d -= 30;
                    ans.month += 1;
                }else
                {
                    ans.day += d;
                    d = 0;
                }
                break;
            case 2:
                leap = isleaq(ans.year) ? 29 : 28;
                rest = leap - ans.day;
                if (d > rest)
                {
                    d -= leap;
                    ans.month += 1;
                }else
                {
                    ans.day += d;
                    d = 0;
                }
                break;
            case 12:
                rest = 31 - ans.day;
                if (d > rest)
                {
                    d -= 31;
                    ans.month = 1;
                    ans.year += 1;
                }else
                {
                    ans.day += d;
                }
                
                break;
            default:
                break;
        }
    }
    
    return ans;
}

std::ostream& operator<<(std::ostream &os, Date date)
{
    char buffer[20];
    sprintf(buffer, "%4d-%02d-%02d", date.year, date.month, date.day);
    os << buffer;
    return os;
}

bool Date::isleaq(int y)
{
    return y % 4 == 0 and y % 100 not_eq 0 or y % 400 == 0;
}

Date &Date::operator=(const Date& d)
{
    this->year = d.year;
    this->month = d.month;
    this->day = d.day;
    return *this;
}

