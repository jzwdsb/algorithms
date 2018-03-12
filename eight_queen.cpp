//
// Created by manout on 18-3-12.
//



#include <cstdlib>

/** queen_col[i] means the i th queen is at i row, queen_col[i] col*/
static int queen_col [8] = {0};

static const int n = 8;

static int count = 0;

void lay_queen(int r)
{
    /** reach 8 row, 0 - 7 row all place a queen*/
    if (r == 8)
    {
        ++count;
        return ;
    }
    /** for this row check all columns */
    for (int i = 0; i < n; ++i)
    {
        queen_col[r] = i;
        bool ok = true;
        /** check previous queen is conflict*/
        for(int j = 0; j < r; ++j)
        {
            if (queen_col[r] == queen_col[j] or abs(r - j) == abs(queen_col[r] - queen_col[j]))
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            /** check next row*/
            lay_queen(r + 1);
        }
    }
}

int eight_queen()
{
    lay_queen(0);
    return count;
}