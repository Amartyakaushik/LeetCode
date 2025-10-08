class Solution {
public:
    string simplifyPath(string path) {
        queue<string> seq; // changed from stack to queue
        int i = 0;

        while (i < (int)path.size()) {
            regex pattern("^[a-zA-Z0-9_.]$");
            string chStr(1, path[i]);

            if (regex_match(chStr, pattern)) {
                string dirName = "";
                while (i < (int)path.size()) {
                    string curChar(1, path[i]);
                    if (regex_match(curChar, pattern)) {
                        dirName += path[i++];
                    } else {
                        break;
                    }
                }
                seq.push(dirName);
                continue;
            }

            switch (path[i]) {
                case '/':
                    while (i < (int)path.size() && path[i] == '/') i++;
                    break;
                case '.': {
                    string temp = "";
                    while (i < (int)path.size() && path[i] == '.') {
                        temp += path[i++];
                    }
                    seq.push(temp);
                    break;
                }
                default:
                    i++;
                    break;
            }
        }

        stack<string> ansStack;

        while (!seq.empty()) {
            string temp = seq.front();
            seq.pop();

            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!ansStack.empty()) ansStack.pop();
            } else {
                ansStack.push(temp);
            }
        }

        if (ansStack.empty()) return "/";

        string ans = "";
        stack<string> revStack;

        while (!ansStack.empty()) {
            revStack.push(ansStack.top());
            ansStack.pop();
        }

        while (!revStack.empty()) {
            ans += "/" + revStack.top();
            revStack.pop();
        }

        return ans;
    }
};

