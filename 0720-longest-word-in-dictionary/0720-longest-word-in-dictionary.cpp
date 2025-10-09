class Solution {
public:
    bool allPrefixesExist(unordered_map<string, int> &present, string& word){
        int size = word.size();
        for (int j = size -1; j > 0; j--) {
                string checkPrev = word.substr(0, j);
                cout << "prev word: " << checkPrev << endl;
                if (present[checkPrev] == 0) return false;
            }
            return true;
    }
    string longestWord(vector<string>& words) {
        unordered_map<string, int> present;
        sort(words.begin(), words.end());
        int maxCount = 0;
        string ans = "";
        for (auto& it : words) {
            present[it]++;
        }
        // for (auto& it : words)
        //     cout << it << " ";
        // cout << endl;
        for (int i = 0; i < words.size(); i++) {
            cout << "iterating ... word: " << words[i] << endl;
            if(allPrefixesExist(present, words[i])){
                int count = words[i].size();
                cout << "count: " << count << " maxC: " << maxCount << endl;
                if (count > maxCount) {
                    maxCount = count;
                    ans = words[i];
                }
                cout << "ans : " << ans << endl;
            }
        }
        return ans;
    }
};