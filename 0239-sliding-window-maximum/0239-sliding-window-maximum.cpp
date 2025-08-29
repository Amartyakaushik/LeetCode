class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     int left = 0, right = left + k -1;
    //     while(left <= nums.size() - k && right < nums.size()){
    //         int max = *max_element(nums.begin() + left, nums.begin() + right + 1);
           
    //         ans.push_back(max);
    //         left++, right++;
    //     }
    //     return ans;
    // }

    vector<int> ans;
    deque<int> dq;
    for(int i = 0; i < nums.size(); i++){
        while(!dq.empty() && dq.front() <= i - k ){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
    }

};