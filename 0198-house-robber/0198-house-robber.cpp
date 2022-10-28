class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size()+3,0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            dp[i]=nums[i]+max(dp[i+2],dp[i+3]);
        }
        return max(dp[0],dp[1]);
    }
};