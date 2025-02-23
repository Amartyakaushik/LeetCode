
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> ms, mt;
        // for (int i = 0; i < s.size(); i++) {
        //     m[s[i]] = t[i];
        // }
        for (int i = 0; i < s.size(); i++) {
            if((ms.count(s[i])) && (ms[s[i]] != t[i])) return false;
            if((mt.count(t[i])) && (mt[t[i]] != s[i])) return false;
            ms[s[i]] = t[i];
            mt[t[i]] = s[i];
        }
        // set<char> st;
        // for (int i = 0; i < t.length(); i++) {
        //     char tt = t[i];
        //     char ss = s[i];

        //     if (m.find(tt) != m.end()) {
        //         if (m[tt] != ss) {
        //             return false;
        //         }
        //     } else {
        //         if (st.find(ss) != st.end()) {
        //             return false;
        //         }
        //         m[tt] = ss;
        //         st.insert(ss);
        //     }
        // }
        return true;
    }
};
