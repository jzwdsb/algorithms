//
// Created by manout on 18-3-1.
//




int remove_right_one(int x)
{
    return x - ((x ^ (x + 1)) >> 1);
}
