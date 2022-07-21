class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i=0,j=0,n=nums.size(),sum=0,res=INT_MAX;
        while(i<n and j<n)
        {
            while(sum>=target)
            {
                res=min(j-i,res);
                sum-=nums[i++];
            }
            sum+=nums[j++];
        }
        while(sum>=target)
        {
            res=min(j-i,res);
            sum-=nums[i++];
        }
        return res==INT_MAX?0:res;
    }
};