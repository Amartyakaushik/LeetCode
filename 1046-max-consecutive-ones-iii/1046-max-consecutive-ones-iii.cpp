class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, ans = 0, maxFreq = 0;
        unordered_map<int, int> freq;
        if(nums.size() == 1 && nums[0] == 0) return 1;
        for(int right = 0; right < nums.size(); right++){
            freq[nums[right]]++;
            maxFreq = max(maxFreq, freq[nums[1]]);
            while(freq[0] > k){
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, (right - left + 1));
        }
        return ans;
    }
};