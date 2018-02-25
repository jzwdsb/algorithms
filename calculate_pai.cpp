//
// Created by manout on 18-2-25.
//


#include <cmath>

float round(float num, int fig)
{
    int shift = static_cast<int>(std::pow(10, fig));
    float half = num >= 0 ? 0.5f : -0.5f;
    return int(num * shift + half) / float(shift);
}

float calculate_pai()
{
    int prefix = 1;
    float ans = 0.0f;
    for (int i = 0; i < 1000; ++i)
    {
        ans += 1 / float(2 * i + 1) * prefix;
        prefix *= -1;
    }
    return 4 * ans;
}
