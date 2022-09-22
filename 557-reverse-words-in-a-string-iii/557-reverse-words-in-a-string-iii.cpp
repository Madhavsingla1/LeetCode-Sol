class Solution {
public:
    string reverseWords(string s) 
    {
        string res;
        int count=0,p=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                string d = s.substr(p,count);
                reverse(d.begin(),d.end());
                res+=d+' ';
                p=i+1;
                count=0;
            }
            else count++;
        }
        if(count)
        {
            string d = s.substr(p,count);
                reverse(d.begin(),d.end());
                res+=d;
        }
        return res;
        
    }
};