class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        long long res=0;
        long long mask = (1LL<<31);
        while(mask)
        {
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(abs(nums[i])&mask)count++;
            }
            if(count%3!=0)
                res+=mask;
            mask=mask>>1;
        }
        // cout<<res;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(res==nums[i])count++;
        }
        return count==1?res:-res;
    }
};