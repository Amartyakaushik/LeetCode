class Solution {
public:
    void solve(set<vector<int>>& ans, vector<int>& nums, vector<int> currPath, int index){
        if(index == nums.size()){
            ans.insert(currPath);
            return;
        }
        // exclude
        solve(ans, nums, currPath, index + 1);
        //include
        currPath.push_back(nums[index]);
        solve(ans, nums, currPath, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> currPath;
        sort(nums.begin(), nums.end());
        solve(ans, nums, currPath, 0);
         vector<vector<int>> finalAns(ans.begin(), ans.end());

        return finalAns;
    }
};