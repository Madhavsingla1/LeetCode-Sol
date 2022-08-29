class Solution {
public:
    bool isPalindrome(string s) {
        string d ;
        for(auto i:s)
        {
            if(isalnum(i))
            {
                if(isupper(i))
                    d+=tolower(i);
                else d+=i;
            }
        }
        string k(d.begin(),d.end());
        reverse(k.begin(),k.end());
        return k==d;
    }
};