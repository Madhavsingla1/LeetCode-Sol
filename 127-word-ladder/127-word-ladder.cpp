class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wl) 
    {
        queue<pair<string,int>>q;
        map<string,bool>vis;
        vis[b]=true;
        set<string>st(wl.begin(),wl.end());
        q.push({b,1});
        while(!q.empty())
        {
            auto d= q.front();
            q.pop();
            if(d.first==e)
                return d.second;
            for(int i=0;i<b.size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    string t = d.first;
                    t[i]=j+'a';
                    if(!vis.count(t) and st.find(t)!=st.end())
                    {
                        vis[t]=1;
                        q.push({t,d.second+1});
                    }
                }
            }
        }
        return 0;
    }
};