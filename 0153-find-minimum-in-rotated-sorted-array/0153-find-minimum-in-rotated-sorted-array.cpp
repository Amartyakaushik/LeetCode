class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 1, right = nums.size() - 1, minEle = nums[0];
        while(left <= right){
            minEle = min({nums[left++], nums[right--], minEle});
        }
        return minEle;
    }
};