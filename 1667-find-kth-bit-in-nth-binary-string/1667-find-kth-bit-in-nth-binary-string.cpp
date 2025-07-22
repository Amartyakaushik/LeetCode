class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1 || n == 1) return '0';
        unordered_set<int> len;
        int stringLen = findLen(n, len);
        
        // if(len.count(k)) return '1';
        int mid =  (1 << (n -1)) ;
        if(k == mid) return '1';
        if(k < mid){
            // return findKthBit(n-1, k);
            return findKthBit(n-1, k);
        }else {
            // return invertBit(findKthBit(n-1, stringLen- k +1));
            return invertBit(findKthBit(n-1, mid - (k - mid)));
        }
    }

    int findLen(int n, unordered_set<int>& len){
        if(n == 1){
            len.insert(1);
            return 1;
        } 
        int length = 2 * findLen(n -1, len) + 1;
        len.insert(length);
        return length;
    }

    char invertBit(char n){
        return (n == '0') ? '1' : '0';
    }
};