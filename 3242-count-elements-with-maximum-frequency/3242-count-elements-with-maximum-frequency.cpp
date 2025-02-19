#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> anotherArr;
        for (int i : nums) {
            anotherArr[i]++;
        }

        int max_freq = 0;
        for (const auto& i : anotherArr) {
            max_freq = max(max_freq, i.second);
        }
        int result = 0;
        for (const auto& i : anotherArr) {
            if (i.second == max_freq) {
                result += i.second;
            }
        }
        return result;
    }
};