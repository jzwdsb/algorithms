//
// Created by manout on 18-2-26.
//

#ifndef ALOGRITHMS_DATE_H
#define ALOGRITHMS_DATE_H

#include <ostream>

class Date
{
public :
    Date():year(0), month(0), day(0){}
    Date(const Date&) = default;
    Date(Date&&) = default;
    Date(int y, int m = 0, int d = 0):year(y), month(m), day(d){}
    
    Date&operator= (const Date&);
    Date operator+(int d);
    
    friend std::ostream& operator << (std::ostream& os, Date date);
    
private :
    
    static bool isleaq(int y);
    int year;
    int month;
    int day;
};


#endif //ALOGRITHMS_DATE_H
