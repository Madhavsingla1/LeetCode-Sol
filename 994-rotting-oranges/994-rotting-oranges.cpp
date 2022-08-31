struct cell{
    int r,c,t;
};

cell create(int r,int c,int t)
{
    cell d;
    d.r= r;
    d.c = c;
    d.t= t;
    return d;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),1));
        queue<cell>q;
        int fresh=0,check=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(create(i,j,0));
                    vis[i][j]=0;
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        int res=0;
        vector<vector<int>>vec= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            cell k=q.front();
            q.pop();
            for(int i=0;i<vec.size();i++)
            {
                cell d;
                d.r = k.r+vec[i][0];
                d.c = k.c+vec[i][1];
                d.t = k.t+1;
                if(d.r>=0 and d.r<grid.size() and d.c>=0 and d.c<grid[0].size() and vis[d.r][d.c] and grid[d.r][d.c]==1)
                {
                    vis[d.r][d.c]=0;
                    check++;
                    q.push(d);
                    res = max(d.t,res);
                }
            }
        }
        if(check==fresh)return res;
        return -1;
    }
};