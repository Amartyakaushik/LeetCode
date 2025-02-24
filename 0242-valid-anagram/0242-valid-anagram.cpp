#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> checkCount;
        for(char c : s){
            checkCount[c]++;
        }
        for(char c : t){
            checkCount[c]--;
        }
        for(const auto& i : checkCount){
            if(i.second > 0) return false;
        }
        if(s.size() != t.size()) return false;
        return true;
    }
};