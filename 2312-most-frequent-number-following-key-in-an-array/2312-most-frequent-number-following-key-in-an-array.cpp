#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> anotherArr;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                anotherArr[nums[i + 1]]++;
            }
        }

        int max_fre_ele = 0, max_freq = INT_MIN;
        for (const auto& it : anotherArr) {
            if (it.second > max_freq) {
                max_freq = it.second;
                max_fre_ele = it.first;
            }
        }
        return max_fre_ele;
    }
};