class Solution {
public:
    bool iseven(int val)
    {  
        int j=0;
        while(val)
        {
            j+=val%10;
            val/=10;
        }
        return j%2==0;
    }
    int countEven(int num) 
    {
        int res=0;
        for(int i=2;i<=num;i++)
        {
            res+=iseven(i)?1:0;
        }
        return res;
        
    }
};