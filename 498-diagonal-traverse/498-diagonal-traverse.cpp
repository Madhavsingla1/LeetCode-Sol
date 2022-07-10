class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int>res;
        map<int,vector<int>>m;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                m[i+j].push_back(mat[i][j]);
            }
        }
        int count=0;
        for(auto i:m)
        {
            auto k = i.second;
            // cout<<k.size()<<endl;
            if(count&1)
            {
                for(int j=0;j<k.size();j++)
                {
                    res.push_back(k[j]);
                }
            }
            else
            {
                for(int j=k.size()-1;j>=0;j--)
                {
                    res.push_back(k[j]);
                }
            }
            count++;
        }
        return res;
        
    }
};