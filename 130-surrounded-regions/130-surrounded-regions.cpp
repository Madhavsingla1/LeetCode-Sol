class Solution {
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(int i,int j,vector<vector<char>>&board)
    {
        if(i<0 or i>=board.size() or j<0 or j>=board[i].size() or board[i][j]!='O')return;
        board[i][j]='A';
        for(int k=0;k<dir.size();k++)
        {
            dfs(i+dir[k][0],j+dir[k][1],board);
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n= board.size(),m = board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
                dfs(0,i,board);
            if(board[n-1][i]=='O')
                dfs(n-1,i,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][m-1]=='O')
                dfs(i,m-1,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='A')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};