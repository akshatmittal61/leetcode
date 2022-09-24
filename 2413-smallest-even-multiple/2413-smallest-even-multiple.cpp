class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(!(n&1))return n;
        else return n*2;
    }
};