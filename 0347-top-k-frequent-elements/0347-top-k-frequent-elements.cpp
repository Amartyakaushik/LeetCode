class Solution {
public:
using IntPair = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        // stored frequency of each element of the array in a hash map 
        for(int i : nums){
            count[i]++;
        }
        // create a min heap that will element with least freq first 
        // using priority queue
        priority_queue<IntPair, vector<IntPair>, greater<IntPair>> minHeap;
        for(auto element : count){
            minHeap.push({element.second, element.first});
            // if size of the heap is more than k means it's storing element with less than top k frequency ele
            if(minHeap.size() > k) minHeap.pop();

        }

        vector<int> ans;
        // for(int i = 0; i < k; i++){
        //     ans.push_back()
        // }
        
        priority_queue<IntPair, vector<IntPair>, greater<IntPair>> tempHeap = minHeap;
        while(!tempHeap.empty()){
            IntPair ele = tempHeap.top();
            int ansEle = ele.second;
            ans.push_back(ansEle);
            tempHeap.pop();
        }
        return ans;
    }
};