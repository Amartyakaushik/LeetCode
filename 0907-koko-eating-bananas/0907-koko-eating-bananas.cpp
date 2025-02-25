class Solution {
public:
    bool check(vector<int>& piles, long mid, int speed) {

        long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += piles[i] / mid;
            if (piles[i] % mid != 0)
                time++;
        }
        return (time <= speed);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // using binary search
        int high = *max_element(piles.begin(), piles.end());
        int low = 1, res = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(piles, mid, h)) {
                high = mid - 1;
                res = mid;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};