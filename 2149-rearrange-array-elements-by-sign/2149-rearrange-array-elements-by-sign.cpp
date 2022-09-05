class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int>po,ne;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)po.push_back(nums[i]);
            else ne.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
                nums[i]=ne[i/2];
            else nums[i]=po[i/2];
        }
        return nums;
        
    }
};