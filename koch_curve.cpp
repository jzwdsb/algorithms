//
// Created by manout on 18-1-22.
//

#include "common_use.h"
#include <boost/format.hpp>

struct point
{
	double x;
	double y;
};

static vector<string> lines;

static void koch(int depth, point p1, point p2)
{
	if (depth == 0)
		return ;
	point s, t, u;
	
	double th = M_PI * 60 / 180;
	
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 2;
	
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * sin(th) + s.y;
	koch(depth - 1, p1, s);
	lines.push_back((boost::format("%1% %2%") % s.x % s.y).str());
	koch(depth - 1, s, u);
	lines.push_back((boost::format("%1% %2%") % u.x % u.y).str());
	koch(depth - 1, u, t);
	lines.push_back((boost::format("%1% %2") % t.x % t.y).str());
	koch(depth - 1, t, p2);
}
