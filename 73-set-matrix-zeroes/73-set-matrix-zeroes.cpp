class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool col=0;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
            {
                col=1;
            }
            for(int j=1;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                // cout<<matrix[i][j]<<" ";
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            // cout<<endl;
        }
        if(matrix[0][0]==0)
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i]=0;
       
        if(col)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
    }
};