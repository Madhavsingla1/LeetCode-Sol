class Solution {
public:
    string breakPalindrome(string p) 
    {
        if(p.size()==1)return "";
        string d = p;
        int i=0;
        while(i<d.size()/2)
        {
            if(d[i]-'a'>0)
            {
                d[i]='a';
                break;
            }
            i++;
        }
        if(d==p)d[d.size()-1]='b';
        return d;
    }
};