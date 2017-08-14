//
// Created by manout on 17-8-14.
//

#include <ctime>
#include <string>
#include <sstream>
using std::string
using std::stringstream;

string run_time(clock_t s, clock_t e)
{
    int second, minute, hour;
    size_t time;
    stringstream ss;
    string ret, buf;
    clock_t t = s - e;
    double time_d = static_cast<double>(t) / CLOCKS_PER_SEC;
    double last = time_d - static_cast<size_t> (time_d);
    if (last >= 0.5)
    {
        time_d += 1;
    }

    time = static_cast<size_t>(time_d);

    second = static_cast<int>(time % 60);
    minute = static_cast<int>((time % 3600) / 60 );
    hour = static_cast<int>(time / 3600);
    if(second != 0)
    {
        ss << second;

    }
    else
    {
        ss << "00";
    }
    if (minute != 0)
    {
        ss << minute;
    }
    else
    {
        ss << "00";
    }
    if (hour != 0)
    {
        ss << hour;
    }
    else
    {
        ss << "00";
    }
    while (ss >> buf)
    {
        if (buf.length() == 2)
        {
            ret += ':' + buf;
        }
        else
        {
            ret += ":0" + buf;
        }
    }
    return ret;
}
