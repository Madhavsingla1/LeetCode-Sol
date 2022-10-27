class Solution {
public:
    int climbStairs(int n) 
    {
        int a=1,b=1;
        n-=1;
        while(n)
        {
            int d= b;
            b+=a;
            a=d;
            n--;
        }
        return b;
    }
};