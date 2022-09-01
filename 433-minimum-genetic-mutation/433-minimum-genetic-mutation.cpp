class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({start,0});
        vector<char>vec={'A','C','G','T'};
        map<string,bool>vis;
        vis[start]=1;
        // int ans =-1;
        while(!q.empty())
        {
            auto d = q.front();
            q.pop();
            if(d.first==end)return d.second;
            for(int j=0;j<8;j++)
            {
                for(int i=0;i<vec.size();i++)
                {
                    string e = d.first;
                    e[j]=vec[i];
                    if(vis.find(e)==vis.end() and st.find(e)!=st.end())
                    {
                        q.push({e,d.second+1});
                        vis[e]=1;
                        // ans = d.second+1;
                    }
                }
            }
        
        }
        return -1;
    }
};