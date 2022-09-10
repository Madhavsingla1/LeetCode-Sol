class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        for(auto i:arr)
            mp[i]++;
        if(mp[0]>1)return 1;
        for(auto i:arr)
            if(mp.count(i*2) and i!=0)
            {
                // cout<<i<<endl;
                return 1;
            }
        return false;
        
    }
};