
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> st;
        for (int i = 0; i < t.length(); i++) {
            char tt = t[i];
            char ss = s[i];

            if (m.find(tt) != m.end()) {
                if (m[tt] != ss) {
                    return false;
                }
            } else {
                if (st.find(ss) != st.end()) {
                    return false;
                }
                m[tt] = ss;
                st.insert(ss);
            }
        }
        return true;
    }
};
