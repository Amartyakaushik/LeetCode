class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& ans, int index) {
        int size = nums.size();
        if(size == 1) ans.insert(nums);
        if(index >= size - 1) return;
        int ix = index;
        while(index < size){
            vector<int> temp = nums;
            swap(temp[ix], temp[index]);
            ans.insert(temp);
            solve(temp, ans, ix + 1);
            index++;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums, ans, 0);
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};