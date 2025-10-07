class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++){
            // cout<<"For i: "<<i<<endl;
            string temp = "";
            unordered_map<char, int> freq;
            freq[ans[0]] = 1;
            // cout<<"freq of "<<ans[0]<<" : "<<freq[ans[0]]<<endl;
            if(ans.size() == 1){
                ans = "1"+ ans;
                // cout<<"ans : "<<ans<<endl;
                continue;
            }
            for(int i = 1; i <= ans.size(); i++){
                // cout<<"ans size: "<<ans.size()<<endl;
                // cout<<"inside inner loop :"<<i<<endl;
                if(i == ans.size()){
                // cout<<"inside inner loop out of loop: but freq["<<i - 1<<"]:"<<freq[i -1]<<endl;
                    temp += to_string(freq[ans[i - 1]]) + ans[i - 1];
                    // cout<<"full size, temp is: "<<temp<<endl;
                    break;
                }
                if(ans[i] != ans[i -1]){
                    temp += to_string(freq[ans[i - 1]]) + ans[i - 1];
                    // cout<<"not equal, temp is: "<<temp<<endl;
                    freq[ans[i]] = 1;
                }else{
                    // cout<<"equal to prev"<<endl;
                    freq[ans[i]]++;
                // cout<<"freq of "<<ans[i]<<" : "<<freq[ans[i]]<<endl;
                }
            }
            ans = temp;
            // cout<<"now ans is: "<<ans<<endl;
        }
        return ans;
    }
};