// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>res(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(!st.empty() and price[st.top().first]<=price[i])
            {
                res[st.top().first]=st.top().second;
                count+=st.top().second;
                st.pop();
            }
            st.push({i,count+1});
        }
        while(!st.empty())
        {
            res[st.top().first]=st.top().second;
                st.pop();
        }
        return res;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends