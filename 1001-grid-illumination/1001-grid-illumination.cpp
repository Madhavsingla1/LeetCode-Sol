class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int>r,c,d1,d2;
        set<pair<int,int>>s;
        for(int i=0;i<lamps.size();i++)
        {
            if(s.find({lamps[i][0],lamps[i][1]})==s.end())
            {
                r[lamps[i][0]]+=1;
                c[lamps[i][1]]+=1;
                d1[lamps[i][0]-lamps[i][1]]+=1;
                d2[lamps[i][0]+lamps[i][1]]+=1;
                s.insert({lamps[i][0],lamps[i][1]});
            }
        }
        vector<int>res;
        int ar[]={-1,-1,-1,0,0,0,1,1,1};
        int br[]={-1,0,1,-1,0,1,-1,0,1};
        for(int i=0;i<queries.size();i++)
        {
            auto d = queries[i];
            if(r[d[0]] or c[d[1]] or d1[d[0]-d[1]] or d2[d[0]+d[1]])
                res.push_back(1);
            else res.push_back(0);
            for(int j=0;j<9;j++)
            {
                int a = d[0]+ar[j],b=d[1]+br[j];
                if(s.find({a,b})!=s.end())
                {
                    r[a]-=1;
                    c[b]-=1;
                    d1[a-b]-=1;
                    d2[a+b]-=1;
                    s.erase({a,b});
                    // cout<<a<<" "<<b<<endl;
                    // cout<<d[0]<<" "<<d[1]<<endl;
                }
            }
        }
        return res;
    }
};