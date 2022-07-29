class Solution {
public:
    int arrangeCoins(int n) {
        long long m = n;
        return (sqrt((m*2*4)+1)-1)/2;
    }
};