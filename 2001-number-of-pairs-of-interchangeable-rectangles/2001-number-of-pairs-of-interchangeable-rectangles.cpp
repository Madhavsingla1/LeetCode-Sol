class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) 
    {
        unordered_map<double,int>mp;
        long long sum=0;
        for(int i=0;i<rec.size();i++)
        {
            double a = (double)rec[i][0]/rec[i][1];
            mp[a]++;
            if(mp[a]>1)
            {
                sum+=mp[a]-1;
            }
        }
        return sum;
    }
};