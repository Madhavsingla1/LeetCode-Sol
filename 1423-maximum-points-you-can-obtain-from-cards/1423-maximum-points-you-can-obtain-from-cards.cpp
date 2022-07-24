class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res=0;
        int sum=0,n=cardPoints.size();
        for(int i=max(0,n-k);i<n;i++)
        {
            sum+=cardPoints[i];
            // cout<<sum<<endl;
        }
        // cout<<sum<<endl;
        res=sum;
        int d=max(0,n-k+1);
        for(int i=d;i<=n;i++)
        {
            sum+=cardPoints[i-d];
            if(i!=0)sum-=cardPoints[i-1];
            // cout<<cardPoints[i-1]<<endl;
            // cout<<"SUm"<<sum<<endl;
            res=max(res,sum);
        }
        return res;
    }
};