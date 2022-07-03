// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	   // if(n==1)return 1;
	    for(int i=1;i<n;i++)
	    {
	        int t= i,count=0;
	        while(t)
	        {
	            count+=t&1;
	            t=t>>1;
	        }
	        if(i+count==n)return 0;
	    }
	    return 1;
	}
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}
  // } Driver Code Ends