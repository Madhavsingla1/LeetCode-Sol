class Solution {
public:
    vector<int> findOriginalArray(vector<int>& cha) 
    {
        if(cha.size()&1)return {};
        sort(cha.begin(),cha.end());
        map<int,int>mp;
        for(auto i:cha)
            mp[i]++;
        
        vector<int>res;
        for(auto i:cha)
        {
            if(mp[i]==0)continue;
            if(mp[i*2]==0)return {};
            res.push_back(i);
            mp[i]--;
            mp[i*2]--;
        }
        return res;
        
    }
};