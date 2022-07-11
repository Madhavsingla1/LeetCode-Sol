class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s2.size()<s1.size())return false;
        map<char,int>ch;
        for(int i=0;i<s1.size();i++)
        {
            ch[s1[i]]++;
        }
        for(int i=0;i<s1.size()-1;i++)
        {
            if(ch.count(s2[i]))
                    ch[s2[i]]--;
        }
        for(int i=s1.size()-1;i<s2.size();i++)
        {
            if(ch.count(s2[i]))
                    ch[s2[i]]--;
            int mx = 0;
            for(auto it = ch.begin();it!=ch.end();it++)
            {
                mx = max(mx,it->second);
            }
            if(mx==0)
            {
                return 1;
            }
            if(ch.count(s2[i-s1.size()+1])){
                ch[s2[i-s1.size()+1]]++;
            }
             
        }
        return 0;
    }
};