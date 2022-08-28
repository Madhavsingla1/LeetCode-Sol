class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long r = 1;
        long e =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)r*=nums[i];
            else e++;
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
                if(e==0)
                {
                    res.push_back(r/nums[i]);
                }
                else if(e==1 and nums[i]==0)
                {
                    res.push_back(r);
                }
                else
                {
                    res.push_back(0);
                }
        }
        return res;
    }
};