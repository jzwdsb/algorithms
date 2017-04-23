#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::unordered_map;

int find_max(vector<int>& input)
{
    int max = 0;
    for(int i = 1; i < input.size(); ++i)
    {
        if(input[i] > max)
            max = input[i];
    }
    return max;
}


int main() {
    int letterCount, retLength;
    int retCount = 0;
    cin >> letterCount >> retLength;
    vector<vector<int>> letterOccurCount(letterCount);
    for(int i = 0; i < letterCount; ++i)
    {
        int row_first;
        cin>>row_first;
        letterOccurCount[i].resize(row_first + 1);
        letterOccurCount[i][0] = row_first;
        for(int j = 1; j <= letterOccurCount[i][0]; ++j)
        {
            cin>>letterOccurCount[i][j];
        }
    }
    string letter;
    for(int i = 0; i < letterCount; ++i)
    {
        int OccurMax = find_max(letterOccurCount[i]);
        while(OccurMax)
        {
            letter.push_back('A' + i);
            --OccurMax;
        }
    }
    unordered_map<string, bool> map;
    auto unique_end  =letter.begin() + retLength;
    while(std::next_permutation(letter.begin(),letter.end())){
        string curr_pat(letter.begin(), unique_end);
        if(map.find(curr_pat) == map.end()) {
            ++retCount;
            map[curr_pat] = true;
        }
    }

    cout<<retCount<<std::endl;
    return 0;
}