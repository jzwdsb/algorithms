//
// Created by manout on 18-3-27.
//


#include <stdio.h>
#include <inttypes.h>
#include <vector>
using namespace std;

struct Segment {
    int64_t start, length;
    bool operator> (Segment& b)
    {
        return this->start > b.start;
    }
    bool operator<(Segment& b)
    {
        return this->start < b.start;
    }
};

void input(vector<vector<Segment>>& segments)
{
    int n;
    scanf("%d", &n);
    segments.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int len;
        scanf("%d", &len);
        segments[i].resize(len);
        for (int j = 0; j < len; ++j)
        {
            scanf("%li %li", &segments[i][j].start, &segments[i][j].length);
        }
    }
}

vector<Segment> merge(vector<vector<Segment>> segments)
{
    vector<Segment> result;
    for (int i = 0; i < segments.size(); ++i)
    {
        for (int j = 0; j < segments[i].size() - 1; ++j)
        {
            Segment min = segments[i][j];
            for (int k = 0; k < segments.size(); ++k)
            {
                if (min > segments[k][j])
                {
                    min = segments[k][j];
                }
            }
            if (min < segments[i][j])
            {
                if (min.start +  min.length > segments[i][j].start)
                {
                    min.length = segments[i][j].start - min.start;
                }
            }
            result.push_back(min);
        }
    }
    return result;
}
void output(const vector<Segment>& result)
{
    vector<Segment>::size_type len = result.size();
    printf("%li", len);
    for (int i = 0; i < len; ++i)
    {
        printf("%li %li", result[i].start, result[i].length);
    }
}
/**
int main(int argc, char** argv)
{
    vector<vector<Segment>> segments;
    input(segments);
    auto result = merge(segments);
    output(result);
    return 0;
}
*/