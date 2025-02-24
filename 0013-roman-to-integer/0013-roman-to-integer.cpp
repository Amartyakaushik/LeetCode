class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500},
                {'M', 1000},
        };
        int ans = roman[s.back()];
        for(int i = 0; i< s.size()-1; i++){
            int sign = (roman[s[i]] < roman[s[i + 1]]) ? -1 : 1;
            ans += sign * roman[s[i]];
        }
        return ans;
    }
};