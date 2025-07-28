class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int>> result;
        for(int i = 0; i < nums.size() -2; i++){
            if(nums[i] > 0 || (i > 0 && nums[i] == nums[i-1]))
                continue;
            int j = i + 1, k = nums.size() - 1; 
            while(j < k){
                int check = nums[i] + nums[j] + nums[k];
                if(check == 0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++, k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k  + 1]) k--;
                }else if(check < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return result;
    }
};