class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       map<int,set<char>>vec,col,row;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int l = (i/3)*3 + (j/3);
                    if(col[j].size() and col[j].find(board[i][j])!=col[j].end())return false;
                    if(row[i].size() and row[i].find(board[i][j])!=row[i].end()) return false;
                    if(vec[l].size() and vec[l].find(board[i][j])!=vec[l].end())return false;
                    col[j].insert(board[i][j]);
                    row[i].insert(board[i][j]);
                    vec[l].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};