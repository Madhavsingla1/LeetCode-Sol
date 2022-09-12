class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score=0;
        int res=0;
        // cout<<j<<endl;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i];
                i++;
            }
            else if(j>i and score>0)
            {
                score--;
                power+=tokens[j--];
            }
            else break;
            // cout<<score<<endl;
            res = max(score,res);
        }
        return res;
        
    }
};