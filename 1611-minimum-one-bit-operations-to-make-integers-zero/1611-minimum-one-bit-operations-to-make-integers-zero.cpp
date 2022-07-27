class Solution {
public:
    int minimumOneBitOperations(int n) {
        long long mask = (1LL<<31);
        long long ans=0;
        bool flag =true;
        while(mask)
        {
            if(mask&n)
            {
                if(flag)
                    ans+=(mask<<1)-1;
                else 
                    ans-=(mask<<1)-1;
                flag=!flag;
                // cout<<mask<<endl;
            }
            mask>>=1;
        }
        return ans;
    }
};