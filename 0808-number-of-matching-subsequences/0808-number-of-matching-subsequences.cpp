class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // int count = 0;
        // for(auto &word : words){
        //         bool found = false, subSeq = true;
        //         int nextIx = 0;
        //     for(int i = 0; i < word.size(); i++){
        //         found = false;
        //         for(int j = nextIx; j < s.size(); j++){
        //             if(s[j] == word[i]){
        //                 nextIx = j + 1;
        //                 found = true;
        //                 break;
        //             }
        //         }
        //         if(!found){
        //             subSeq = false;
        //             break;
        //         }
        //     }
        //     if(subSeq) count++;
        // }
        // return count;
        vector<vector<pair<string::iterator, string::iterator>>> bucket(26);
        for(auto &word : words){
            bucket[word[0] - 'a'].push_back({word.begin(), word.end()});
        }
        int count = 0;
        for(char c : s){
            auto current = bucket[c - 'a'];
            bucket[c - 'a'].clear();

            for(auto [startIx, endIx] : current){
                startIx++;
                if(startIx == endIx) count++;
                else bucket[*startIx - 'a'].push_back({startIx, endIx});
            }
        }
        return count;
    }
};