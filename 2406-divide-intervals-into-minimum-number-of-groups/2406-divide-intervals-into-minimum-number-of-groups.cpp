class Solution {
public:
    int minGroups(vector<vector<int>>& in) 
    {
        vector<int>vec(1e7+1,0);
        int mx = INT_MIN;
        for(auto i:in)
        {
            vec[i[0]]++;
            vec[i[1]+1]--;
            mx = max(mx,i[1]+1);
        }
        
        int res = 0, sum=0;
        for(int i=0;i<mx+1;i++)
        {
            sum+=vec[i];
            res =max(sum,res);
        }
        return res;
    }
};