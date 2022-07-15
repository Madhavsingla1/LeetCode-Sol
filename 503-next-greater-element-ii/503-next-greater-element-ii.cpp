class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int>st,s;
        int n= nums.size(),mx=INT_MIN,ind=-1;
        vector<int>res(n,INT_MIN);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=nums[i])
                st.pop();
            if(st.empty())res[i]=-1;
            else res[i]=st.top();
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=nums[i])
                st.pop();
            if(st.empty())res[i]=-1;
            else res[i]=st.top();
            st.push(nums[i]);
        }
        return res;
    }
};