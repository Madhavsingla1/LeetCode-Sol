class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        long long n= arr.size();
        vector<long long>b(n),f(n);
        stack<long long>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>arr[i])
            {
                f[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            f[st.top()]=n;
            st.pop();
        }
        st.push(n-1);
        for(int j=n-2;j>=0;j--)
        {
            while(!st.empty() and arr[st.top()]>=arr[j])
            {
                b[st.top()]=j;
                st.pop();
            }
            st.push(j);
        }
        while(!st.empty())
        {
            b[st.top()]=-1;
            st.pop();
        }
        long long res=0;
        int mod =1e9+7;
        for(int i=0;i<n;i++)
        {
            res+=((((f[i]-i)*(i-b[i]))%mod)*(arr[i]%mod))%mod;
            res=res%mod;
        }
        return res%mod;
        
    }
};