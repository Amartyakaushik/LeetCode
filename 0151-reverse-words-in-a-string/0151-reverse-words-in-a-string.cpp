#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        // int l = 0, r = s.length()-1;
        // while(l < r){
        //     swap(s[l++] , s[r--]);
        // }

        stack<string> str;
        string temp = "";
        for(int i = 0; i< s.length(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }else if(!temp.empty()){
                str.push(temp);
                temp = "";
            }
        }

        if(!temp.empty()){
            str.push(temp);
        }
        temp = "";

        while(!str.empty()){
            temp += str.top();
            str.pop();
            if(!str.empty()){
                temp += " ";
            }
        }
        return temp;
    }
};