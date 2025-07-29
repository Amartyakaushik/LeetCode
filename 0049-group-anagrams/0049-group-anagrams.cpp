#include<algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // brute force
        // vector<vector<string>> ans;
        // unordered_map<string, bool> checked;
        // for(int i = 0; i < strs.size(); i++){
        //     string tempStr = strs[i];  
        //     string sortedTempStr = tempStr;
        //     sort(sortedTempStr.begin(), sortedTempStr.end());
        //     if(!checked[sortedTempStr]){
        //         vector<string> temp;
        //         for(int j = i + 1; j < strs.size(); j++){
        //             string nextSortedStr = strs[j];
        //             sort(nextSortedStr.begin(), nextSortedStr.end());
        //             if((sortedTempStr) == (nextSortedStr)){
        //                 temp.push_back(strs[j]);
        //             }
        //         }
        //         temp.push_back(tempStr);
        //         ans.push_back(temp);
        //         checked[sortedTempStr] = true;
        //     }
                
        //     }
        // return ans;
        unordered_map<string, vector<string>> anagramGrp;
        // create key and store all matching strings related after sorting
        for(auto &str : strs){
            string key = str;
            sort(key.begin(), key.end());
            anagramGrp[key].emplace_back(str);
        }
        // now just add all the values of each key 
        vector<vector<string>> ans;
        for(auto &pair : anagramGrp){
            ans.emplace_back(pair.second);
        }
        return ans;
        }
};