// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int n, long long a[]){
        long long res=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(a[i])
            {
                if(a[i]&1)count++;
                if(count>1)break;
                a[i]=a[i]>>1;
            }
            if(count==1)
            {
                res+=res+1;
            }
        }
        
        long mod = 1e9+7;
        return res%mod;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
}   // } Driver Code Ends