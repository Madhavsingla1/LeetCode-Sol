class Solution {
    bool res=1;
public:
    void dfs(int i,vector<vector<int>>&graph,vector<int>&vis,int val)
    {
        if(vis[i]!=-1)return;
        // cout<<val<<endl;
        vis[i]=val%2;
        val++;
        for(int j=0;j<graph[i].size();j++)
        {
            if(vis[graph[i][j]]==-1)
                dfs(graph[i][j],graph,vis,val);
            else if(vis[graph[i][j]]!=val%2) 
            {
                res=0;
                break;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==-1)dfs(i,graph,vis,0);
            if(!res)break;
        }
        // for(int i=0;i<vis.size();i++)
        //     cout<<vis[i]<<" ";
        // cout<<endl;
        return res;
        
    }
};