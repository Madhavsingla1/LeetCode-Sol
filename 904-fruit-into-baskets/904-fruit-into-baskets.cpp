class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>mp;
        int res=0,i=0,j=0;
        while(j<f.size())
        {
            mp[f[j++]]++;
            while(mp.size()>2)
            {
                mp[f[i]]--;
                if(mp[f[i]]==0)mp.erase(f[i]);
                i++;
            }
            res=max(j-i,res);
        }
        return res;
    }
};