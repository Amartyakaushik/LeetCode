class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // vector<int> temp = nums;
        // sort(temp.begin(), temp.end());
        // int greatestELe = temp[temp.size()-1];
        // auto it = find(nums.begin(), nums.end(), greatestELe);
        // int ans = distance(nums.begin(), it);
        // return ans;

        int left = 0, right = nums.size() -1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1]) right = mid;
            if(nums[mid] < nums[mid + 1]) left = mid + 1;
            if(left == right) break;
        }
        return left;
    }
};