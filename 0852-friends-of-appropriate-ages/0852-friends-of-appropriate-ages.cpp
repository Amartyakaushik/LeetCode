class Solution {
public:
    int firstGreater(vector<int>& ages, int x) {
        int left = 0, right = ages.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (ages[mid] <= x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        unordered_map<int, int> present;
        int totalReq = 0;
        set<int> repeatedAge;
        present[ages[0]]++;

        int left = 0, right = 0, n = ages.size();
        for (int i = 0; i < n; i++) {
            int curr = ages[i];
            while (left < n && ages[left] <= 0.5 * curr + 7)
                left++;
            while (right < n && ages[right] <= curr)
                right++;

            if (right > left + 1) {
                totalReq += (right - left - 1); 
            }
        }
        //                       This gave me a TLE while passing
        // for(int i = ages.size() -1; i > 0; i--){
        //     present[ages[i]]++;
        //     for(int j = i - 1; j >= 0; j--){
        //         int curr = ages[i], prev = ages[j];
        //         cout<<"curr: "<<curr<<" prev: "<<prev<<endl;
        //         if(curr == prev){
        //             repeatedAge.insert(curr);
        //             continue;
        //         }
        //         if(prev > (0.5 * curr + 7) && prev <= curr && (!(prev > 100
        //         && curr < 100))){
        //             cout<<curr<<" passed with "<<prev<<endl;
        //             totalReq += 1;
        //             cout<<"after adding 1 totalReq : "<<totalReq<<endl;
        //         }

        //     }
        //     cout<<endl<<endl;
        // }

        for (int age : repeatedAge) {
            if (age > (0.5 * age + 7)) {
                int k = present[age];
                totalReq += k * (k - 1);
            }
        }
        return totalReq;
    }
};