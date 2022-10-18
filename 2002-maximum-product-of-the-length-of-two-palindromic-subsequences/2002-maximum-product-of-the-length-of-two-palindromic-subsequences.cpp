class Solution {
public:
    bool ispal(string d)
    {
        string s=d;
        reverse(s.begin(),s.end());
        return d==s;
    }
    int maxProduct(string s) 
    {
        map<int,int>mp;
        for(int i=1;i<1<<s.size();i++)
        {
            string d;
            for(int j=0;j<s.size();j++)
            {
                int mask = 1<<j;
                if(i&mask)
                {
                    d+=s[j];
                }
            }
            if(ispal(d))
            {
                mp[i]=d.size();
            }
        }
        int res=1;
        for(auto i:mp)
        {
            for(auto j:mp)
            {
                if(!(i.first&j.first))
                {
                    res = max(res,i.second*j.second);
                }
            }
        }
        return res;
        
    }
};