class Solution {
public:
    string pushDominoes(string dom) 
    {
        vector<int>vec(dom.size(),0);
        int add=0;
        for(int i=0;i<dom.size();i++)
        {
            if(dom[i]=='R')add = dom.size();
            else if(dom[i]=='L')add=0;
            else add = max(add-1,0);
            vec[i]+=add;
        }
        add=0;
        for(int i=dom.size()-1;i>=0;i--)
        {
            if(dom[i]=='L')add = dom.size();
            else if(dom[i]=='R')add=0;
            else add = max(add-1,0);
            vec[i]-=add;
        }
        string res;
        for(auto i:vec)
            res+= i>0?'R':i<0?'L':'.';
        return res;
    }
};