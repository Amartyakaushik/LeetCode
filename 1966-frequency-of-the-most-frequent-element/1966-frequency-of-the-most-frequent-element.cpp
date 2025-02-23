#include<bits/stdc++.h>
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFreq = 1, start = 0, end = 0;
        long sum = 0;
        sort(nums.begin(), nums.end());
        while(end < nums.size()){
            sum += nums[end++];
            if( (sum + k) < ((long) nums[end-1] * (end-start))){
                sum -= nums[start++];
            }
            maxFreq = max(maxFreq, end-start);
        }
        return maxFreq;
        // map<int, int> freq;
        // for(int i : nums){
        //     freq[i]++;
        // }
        // // for(const auto& i : freq){
        // //     for(auto& j : freq){
        // //         if((j.first - i.first) < k){
        // //             j.second++;
        // //         }
        // //     }
        // // }
        // // for(const auto& i : freq){
        // //     maxFreq = max(maxFreq, i.second);
        // // }

        //     int ele = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     int initFreq = 1;
        //     for(int j = i; j< nums.size(); j++){
        //         if(((nums[j] - nums[i]) > 0) && ((nums[j] - nums[i]) <= k)){
        //             // maxFreq = max(maxFreq, (nums[j+1] - nums[j]));
        //             freq[nums[j]]++;
        //             initFreq++;
        //             ele = nums[j];
        //         } 
        //     }
        //     // maxFreq = max(maxFreq, initFreq);
        // }
        // // return nums[nums.size()-1];
        // // return ele;
        // // return maxFreq;
        // // int dd = 0;
        // for(const auto& i : freq){
        //     // int pre = maxFreq;
        //     maxFreq = max(maxFreq, i.second);
        //     // if(pre != maxFreq){
        //     //     dd = i.first;
        //     // }
        // }
        // return maxFreq;
        // // return freq[dd];
        // // return dd;
    }
};