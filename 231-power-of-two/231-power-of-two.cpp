class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        // long long num=1;
        // while(n>num)
        // {
        //     num=num<<1;
        // }
        // return num==n;
        if(n<=0)return 0;
        return !(n&(n-1));
    }
};