class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<long long>left(26,0),right(26,0);
        for(auto i:s)right[i-'a']++;
        unordered_set<string>res;
        
        // cout<<"ES"<<endl;
        for(int i=0;i<s.size();i++)
        {
            right[s[i]-'a']--;
            for(char j='a';j<='z';j++)
            {
                if(left[j-'a']>0 and right[j-'a']>0)
                {
                    string k;
                    k.push_back(j);
                    k.push_back(s[i]);
                    k.push_back(j);
                    res.insert(k);
                }
            }
            left[s[i]-'a']++;
        }
        return res.size();
    }
};