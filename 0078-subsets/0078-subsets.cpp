class Solution {
    private:
        void subset(vector<int>nums, int index, vector<int> output, vector<vector<int>> &ans){
            if(index >= nums.size()){
                ans.push_back(output);
                return;
            }
            subset(nums, index+1, output, ans);

            output.push_back(nums[index]);
            subset(nums, index+1, output, ans);
            output.pop_back();
            // return;
        }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        subset(nums, 0, output, ans);
        return ans;
    }
};