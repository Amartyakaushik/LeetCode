class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j  > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int leftPtr = j + 1, rightPtr = nums.size() - 1;
                while (leftPtr < rightPtr) {

                    long long targetSum = 1LL *  nums[i] + nums[j] + nums[leftPtr] + nums[rightPtr];
                    if (target == targetSum) {
                        result.push_back(
                            {nums[i], nums[j], nums[leftPtr], nums[rightPtr]});
                        leftPtr++, rightPtr--;

                        while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1]) leftPtr++;
                        while (leftPtr < rightPtr && nums[rightPtr] == nums[rightPtr + 1]) rightPtr--;
                    } else if (target > targetSum)
                        leftPtr++;
                    else
                        rightPtr--;
                }
            }
        }
        return result;
    }
};