class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},{'V', 5},{'X', 10}, {'L', 50}, {'C', 100},{'D', 500},{'M',1000}
    };
    int num = romanMap.at(s.back());
    for(int i = s.length() - 2; i >= 0; --i){
        if(romanMap.at(s.at(i)) < romanMap.at(s.at(i + 1)))
            num -= romanMap.at(s.at(i));
        else
            num += romanMap.at(s.at(i));
    }
    return num;
    }
};
