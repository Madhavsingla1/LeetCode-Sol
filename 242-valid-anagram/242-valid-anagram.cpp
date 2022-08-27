class Solution {
public:
    bool isAnagram(string s, string t) {
     // sort(s.begin(),s.end());
     //    sort(t.begin(),t.end());
     //    return s==t;
        unordered_map<char,int>mp;
        for(auto i:s)
            mp[i]++;
        for(auto i:t)
        {
            mp[i]--;
            if(mp[i]==0)mp.erase(i);
        }
        return !mp.size();
    }
};