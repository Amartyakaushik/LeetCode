class Solution {
public:
    int findByBinary(vector<int>& nums, int low, int high, int target){
            while(low <= high){
            int mid = (low + high) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
    }
    int search(vector<int>& nums, int target) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int maxIx = (find(nums.begin(), nums.end(), maxEle)) - nums.begin();
        // left side
        int ans = -1;
        if(nums[0] <= target){
            int low = 0, high = maxIx;
            ans = findByBinary(nums, low, high, target);
        }else{  // right side
            int low = maxIx + 1, high = nums.size() - 1;
            ans = findByBinary(nums, low, high, target);
        }
        return ans;
    }
};