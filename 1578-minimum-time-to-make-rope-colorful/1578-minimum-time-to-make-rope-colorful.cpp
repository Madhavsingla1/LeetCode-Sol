class Solution {
public:
    int minCost(string c, vector<int>& nt) 
    {
        int res=0;
        for(int i=0;i<nt.size();i++)
        {
            int j=i;
            int sum=nt[i];
            int mx= nt[i];
            while(c[j]==c[i+1])
            {
                sum+=nt[i+1];
                mx = max(mx,nt[i+1]);
                i++;
            }
            res+=sum-mx;
        }
        return res;
        
    }
};