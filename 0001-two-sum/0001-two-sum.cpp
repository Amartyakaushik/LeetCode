class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int i = 0, j = nums.size() - 1;
        // vector<int> ans[2];
        unordered_map<int, int> save_index;
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(save_index.count(rem)){
                return {save_index[rem], i};
            }

            save_index[nums[i]] = i;
            // if((nums[i] + nums[j]) == target){
            //     ans.push_back(i);
            //     ans.push_back(j);
            //     return ans;
            // }
            // if(j > target)
        }
        return {};
    }
};