class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0 or nums[i]>nums.size())
                nums[i]=nums.size()+1;
        }
        for(auto i:nums)
        {
            if(abs(i)<=nums.size() and nums[abs(i)-1]>0)nums[abs(i)-1]*=-1;
        }
        
        for(auto i:nums)
        {
            if(i<0)
                res++;
            else return res;
        }
        return res;
        
    }
};