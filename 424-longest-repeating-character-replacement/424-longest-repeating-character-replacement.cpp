class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int>mp;
        // int count=0;
        int res=1,i=0,j=1,count=1,maxcount=0;
        mp[s[0]]++;
        while(j<s.size())
        {
            mp[s[j]]++;
            maxcount=max(maxcount,mp[s[j]]);
            while(j-i+1-maxcount>k)
                mp[s[i++]]--;
            
            res = max(j-i,res);
            j++;
        }
        res = max(j-i,res);
        return res;
    }
};