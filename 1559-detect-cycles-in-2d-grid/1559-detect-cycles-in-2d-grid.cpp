class Solution {
    vector<vector<bool>>vis;
    bool res=0;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(int i,int j,vector<vector<char>>&grid,pair<int,int>prev)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[i].size() or grid[i][j]!=grid[prev.first][prev.second])return;
        if(vis[i][j])
        {
            res=1;
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<dir.size();k++)
        {
            int x= i+dir[k][0];
            int y= j+dir[k][1];
            if(x==prev.first and y==prev.second)continue;
            else {
                dfs(x,y,grid,{i,j});
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) 
    {
        vis.resize(grid.size(),vector<bool>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!vis[i][j])dfs(i,j,grid,{i,j});
                if(res)break;
            }
            if(res)break;
        }
        return res;
    }
};