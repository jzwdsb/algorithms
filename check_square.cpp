//
// Created by manout on 18-3-23.
//
#include <vector>
#include <cmath>

#define INDEX(i) ((i) + 4) % 4

using std::vector;

struct Point
{
    int x;
    int y;
};



double point_distance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double angle(Point a, Point b, Point c)
{
}

bool check_square(vector<Point>& points)
{
    double distance = point_distance(points[0], points[1]);
    for (int i = 1; i < 3; ++i)
    {
        if (point_distance(points[i], points[i + 1]) not_eq distance)
        {
            return false;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
    
    }
}
