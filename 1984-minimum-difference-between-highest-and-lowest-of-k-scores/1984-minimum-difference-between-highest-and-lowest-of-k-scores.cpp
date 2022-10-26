class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        int i=0,j=k-1;
        while(j<nums.size())
        {
            res = min(res,nums[j]-nums[i]);
            i++;
            j++;
        }
        return res==INT_MAX?0:res;
    }
};