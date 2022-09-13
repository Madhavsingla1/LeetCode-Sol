class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        map<int,int>mp;
        for(int i=0;i<roads.size();i++)
        {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        vector<pair<int,int>>vec(n);
        int t =0;
        for(auto i:mp)
        {
            vec[t++]={i.second,i.first};
        }
        // cout<<"YES"<<endl;
        sort(vec.begin(),vec.end());
        vector<int>dec(n,0);
        for(int i=0;i<n;i++)
        {
            dec[vec[i].second]=i+1;
        }
        long long res=0;
        // cout<<"YES"<<endl;
        for(int i=0;i<roads.size();i++)
        {
            res += dec[roads[i][0]]+dec[roads[i][1]];
        }
        return res;
        
    }
};