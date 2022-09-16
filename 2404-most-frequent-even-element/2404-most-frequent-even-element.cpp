class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        map<int,int>mp;
        for(auto i:nums)
        {
            if(!(i&1))mp[i]++;
        }
        int val = -1,mx = INT_MIN;
        for(auto i:mp)
        {
            if(mx<i.second)
            {
                val=i.first;
                mx = i.second;
            }
        }
        return val;
        
    }
};