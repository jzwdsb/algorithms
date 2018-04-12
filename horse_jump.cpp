//
// Created by manout on 18-4-9.
//

static int x, y;

static unsigned long int dfs(int x_, int y_, int k)
{
    if (x_ == x and y_ == y)
        return 1;
    if (x_ < 0 or x_ > 8 or y_ < 0 or y_ > 8 or k == 0)
        return 0;
    unsigned long int ans = 0;
    ans += dfs(x_ + 1, y_ + 2, k - 1);
    ans += dfs(x_ + 2, y_ + 1, k - 1);
    ans += dfs(x_ + 2, y_ - 1, k - 1);
    ans += dfs(x_ + 1, y_ - 2, k - 1);
    ans += dfs(x_ - 1, y_ - 2, k - 1);
    ans += dfs(x_ - 2, y_ - 1, k - 1);
    ans += dfs(x_ - 2, y_ + 1, k - 1);
    ans += dfs(x_ - 1, y_ + 2, k - 1);
    return ans;
}


unsigned long int horse_jump(int k, int x_, int y_)
{
    x = x_;
    y = y_;
    return dfs(0, 0, k);
}