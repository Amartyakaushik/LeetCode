#include<bits/stdc++.h>
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        vector<pair<int, char>> vp;
        for(char c : s){
            vp.push_back(
                make_pair(mp[c], c)
            );
        }
        sort(vp.begin(), vp.end(), greater<>());
        string temp = "";
        for(int i = 0; i< vp.size(); i++){
            temp += vp[i].second;
        }
        return temp;
    }
};