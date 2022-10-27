class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        long long i=0,j=1,val=0,ans=1;
        while(j<nums.size())
        {
            int d = nums[j]-nums[j-1];
            if(d*(j-i)<=k-val)
            {
                val+=d*(j-i);
                j++;
            }
            else
            {
                val-=nums[j-1]-nums[i];
                val =max(val,0LL);
                i++;
            }
            ans=max(j-i,ans);
        }
        return ans;
    }
};