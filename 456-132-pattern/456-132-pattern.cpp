class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        stack<int>st;
        int low = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<low)
            {
                return true;
            }
            while(!st.empty() and st.top()<nums[i])
            {
                low=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};