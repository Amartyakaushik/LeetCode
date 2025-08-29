class Solution {
public:
    string minWindow(string s, string t) {
        int targetSize = t.size(), windowSize = s.size();
        unordered_map<char, int> need, window;
        for (char& c : t) {
            need[c]++;
        }

        int start = 0, minStart = -1, minLength = INT_MAX, matches = 0;
        for (int i = 0; i < windowSize; i++) {
            window[s[i]]++;
            if (need[s[i]] >= window[s[i]]) {
                ++matches;
            }

            while (matches == targetSize) {
                if (i - start + 1 < minLength) {
                    minLength = i - start + 1;
                    minStart = start;
                }

                if (need[s[start]] >= window[s[start]]) {
                    --matches;
                }
                    --window[s[start++]];
            }
        }
        return minStart < 0 ? "" : s.substr(minStart, minLength);
    }
};
// 