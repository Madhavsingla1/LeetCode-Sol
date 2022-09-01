struct cell{
    int x,y,dis;
    cell(){};
    cell(int x1,int y1,int dis1)
    {
        x=x1;
        y=y1;
        dis=dis1;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),1));
        queue<cell>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(cell(i,j,0));
                    vis[i][j]=0;
                }
            }
        }
        if(q.size()==0 or q.size()==grid.size()*grid[0].size())return -1;
        vector<vector<int>>vec={{1,0},{-1,0},{0,-1},{0,1}};
        int ans =0;
        while(!q.empty())
        {
            auto d = q.front();
            q.pop();
            for(int i=0;i<vec.size();i++)
            {
                cell k = cell(d.x+vec[i][0],d.y+vec[i][1],d.dis+1);
                if(k.x>=0 and k.x<grid.size() and k.y>=0 and k.y<grid[0].size() and vis[k.x][k.y] and grid[k.x][k.y]==0)
                {
                    // cout<<d.x<<" "<<d.y<<endl;
                    vis[k.x][k.y]=0;
                    ans = k.dis;
                    q.push(k);
                }
            }
        }
        return ans;
        
    }
};