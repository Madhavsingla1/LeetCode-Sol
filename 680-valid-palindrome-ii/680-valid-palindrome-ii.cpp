class Solution {
public:
    bool ispla(string s)
    {
        string d = s;
        reverse(d.begin(),d.end());
        return d==s;
    }
    bool validPalindrome(string s) 
    {
        int i=0,j=s.size()-1;
        // int d = 1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                string d = s;
                s.erase(i,1);
                d.erase(j,1);
                return ispla(d) or ispla(s);
            }
            i++;
            j--;
        }
        return true;
    }
};