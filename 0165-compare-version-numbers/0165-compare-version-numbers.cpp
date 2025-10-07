class Solution {
public:
    int compareVersion(string version1, string version2) {

        // if (stoi(version1) < stoi(version2))
        //     return -1;
        // else if (stoi(version1) > stoi(version2))
        //     return 1;
        // int ver1Ix = 0, ver2Ix = 0;
        // int ver1Len = version1.size(), ver2Len = version2.size();
        // string ver1 = "", ver2 = "";
        // while (ver1Ix < ver1Len && version1[ver1Ix] != '.')
        //     ver1Ix++;
        // while (ver2Ix < ver2Len && version2[ver2Ix] != '.')
        //     ver2Ix++;
        // int size = min((ver1Len - ver1Ix), (ver2Len - ver2Ix));
        // cout << "size" << size << endl;
        // int i = 0;
        // while (i < size) {
        //     cout << "checking at v1x: " << ver1Ix << " v2x: " << ver2Ix << endl;
        //     cout << "value at v1x: " << version1[ver1Ix]
        //          << " v2x: " << version2[ver2Ix] << endl;
        //     if ((version1[ver1Ix] == '.' && version2[ver2Ix] == '.')) {
        //         ver1Ix++, ver2Ix++, i++;
        //         continue;
        //     }
        //     if (ver1Ix < ver1Len && version1[ver1Ix] == '.') {
        //         while (ver2Ix < ver2Len && version2[ver2Ix] != '.') {
        //             ver2 += version2[ver2Ix++];
        //         }
        //         ver1Ix++;
        //     }
        //     if(ver2Ix < ver2Len && version2[ver2Ix] ==  '.'){
        //         while(ver1Ix < ver1Len && version1[ver1Ix] !=  '.'){
        //             ver1 += version1[ver1Ix++];
        //         }
        //         ver2Ix++;
        //     }
        //     // ver2 += version2[ver2Ix++], ver1 += version1[ver1Ix++];
            
        //     if(ver2Ix < ver2Len) ver2 += version2[ver2Ix++];
        //     if(ver1Ix < ver1Len) ver1 += version1[ver1Ix++];
        //     i++;
        // }
        // while (ver1Ix < ver1Len) {
        //     if (version1[ver1Ix] == '.') {
        //         ver2 += "0";
        //         ver1Ix++;
        //         continue;
        //     }
        //     ver1 += version1[ver1Ix++];
        // }
        // while (ver2Ix < ver2Len) {
        //     if (version2[ver2Ix] == '.') {
        //         ver1 += "0";
        //         ver2Ix++;
        //         continue;
        //     }
        //     ver2 += version2[ver2Ix++];
        // }
        // cout << ver1 << " " << ver2 << endl;
        // if (ver1.empty() && ver2.empty()) {
        //     cout << "1" << endl;
        //     if (stoi(version1) < stoi(version2))
        //         return -1;
        //     else if (stoi(version1) > stoi(version2))
        //         return 1;
        //     else
        //         return 0;

        // } else {
        //     cout << "2" << endl;
        //     if (stoi(ver1) < stoi(ver2))
        //         return -1;
        //     else if (stoi(ver1) > stoi(ver2))
        //         return 1;
        //     else
        //         return 0;
        // }

        int ver1Ix = 0, ver2Ix = 0; 
int ver1Len = version1.size(), ver2Len = version2.size();

while (ver1Ix < ver1Len || ver2Ix < ver2Len) {
    string ver1Segment = "", ver2Segment = "";

    while (ver1Ix < ver1Len && version1[ver1Ix] != '.') {
        ver1Segment += version1[ver1Ix++];
    }
    ver1Ix++; // skip '.'

    while (ver2Ix < ver2Len && version2[ver2Ix] != '.') {
        ver2Segment += version2[ver2Ix++];
    }
    ver2Ix++; // skip '.'

    int num1 = ver1Segment.empty() ? 0 : stoi(ver1Segment);
    int num2 = ver2Segment.empty() ? 0 : stoi(ver2Segment);

    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
}
// all segments equal
return 0;

    }
};