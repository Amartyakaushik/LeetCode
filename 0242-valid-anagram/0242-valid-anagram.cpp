class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> checkS;
        unordered_map<char, int> checkT;
        for(char c : s){
            checkS[c]++;
        }
        for(char c : t){
            checkT[c]++;
        }
        for(char c : t){
            if(checkS[c] != checkT[c]) return false;
        }
        return true;
    }
};