#include<bitset>
class Solution {
public:
    int kthGrammar(int n, int k) {
        bitset<32> b(k-1);
        int bitCount = b.count() & 1;
        if(bitCount == 1)
            return 1;
        else if(bitCount == 0) 
            return 0;
            return 0;
    }
};