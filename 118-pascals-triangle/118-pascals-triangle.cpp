class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>vec;
        if(numRows==0)return vec;
        vec.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int>d;
            d.push_back(1);
            int k =1;
            for(int j=0;j<vec[i-1].size()-1;j++)
            {
                k+=vec[i-1][j+1];
                d.push_back(k);
                k-=vec[i-1][j];
            }
            d.push_back(k);
            vec.push_back(d);
        }
        return vec;
        
    }
};