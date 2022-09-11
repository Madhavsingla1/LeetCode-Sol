class Solution {
public:
    int longestPalindrome(string s) 
    {
        map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        int res=0;
        int change = 0;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second&1)
            {
                if(i->second>1)
                    res+=i->second-1;
                change=1;
            }
            else res+=i->second;
        }
        
        return res+change;
    }
};