class Solution {
public:
    bool check(vector<int>& piles, long mid, int speed){
        long time = 0;
        for(int i : piles){
            time += (i / mid);
            if((i % mid) != 0) time++;
        }
        return (time <= speed);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int ans = high, low = 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(piles, mid, h)){
                high = mid -1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};