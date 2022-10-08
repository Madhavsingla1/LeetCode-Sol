class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(), res=INT_MAX,r=0;
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(abs(target-nums[i]-nums[j]-nums[k])<res)
                {
                    res=   abs(target-nums[i]-nums[j]-nums[k]); 
                    // cout<<nums[i]<<nums[j]<<nums[k]<<endl;
                    r=nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]+nums[k]==target)return r;
                else if(nums[i]+nums[j]+nums[k]>target)k--;
                else j++;
            }
        }
        return r;
        
    }
};