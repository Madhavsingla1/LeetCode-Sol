class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(!mp.count(i-j))mp[i-j]=matrix[i][j];
                else if(mp[i-j]!=matrix[i][j])
                {
                    return false;
                }
                
            }
        }
    return true;
        
    }
};