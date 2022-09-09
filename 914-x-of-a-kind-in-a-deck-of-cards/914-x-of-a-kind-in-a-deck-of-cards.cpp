class Solution {
public:
    int gcd(int x,int y)
    {
        return x==0?y:gcd(y%x,x);
    }
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        vector<int>count(1e4+3,0);
        for(int i=0;i<deck.size();i++)
            count[deck[i]]++;
        
        int g=-1;
        for(int i=0;i<=1e4;i++)
        {
            if(count[i]>0)
            {
                if(g==-1)
                    g=count[i];
                else 
                    g=gcd(g,count[i]);
            }
        }
        return g>=2;
    }
    
};