class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        long long num=1;
        while(n>num)
        {
            num=num<<1;
        }
        return num==n;
    }
};