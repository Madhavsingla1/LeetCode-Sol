class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++)
        {
           if(grid[i][0]!=1)
           {
                for(int j=0;j<grid[0].size();j++)
                {
                    grid[i][j]=grid[i][j]?0:1;
                }
           }
        }
        for(int i=0;i<grid[0].size();i++)
        {
            int zero=0;
            for(int j=0;j<grid.size();j++)
            {
                zero+=grid[j][i]==0;
            }
            if(zero>grid.size()/2)
            {
                for(int j=0;j<grid.size();j++)
                {
                    grid[j][i]=grid[j][i]?0:1;
                }
            }
        }
        long long res=0;
        for(auto i:grid)
        {
            reverse(i.begin(),i.end());
            long long sum=0;
            for(int j=0;j<i.size();j++)
            {
                if(i[j])
                {
                    sum+=pow(2,j);
                }
            }
            cout<<sum<<endl;
            res+=sum;
        }
        return res;
        
    }
};