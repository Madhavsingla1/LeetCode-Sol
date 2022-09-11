class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int n= nums.size();
        stack<int>st;
        vector<int>dp(n,0);
        int res=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()]<nums[i])
            {
                dp[i] = max(++dp[i],dp[st.top()]);
                res = max(dp[i],res);
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};