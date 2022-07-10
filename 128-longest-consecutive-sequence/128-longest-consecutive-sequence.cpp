class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>m;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                int ls =0,rs=0;
                if(m.find(nums[i]-1)!=m.end())ls=m[nums[i]-1];
                if(m.find(nums[i]+1)!=m.end())rs=m[nums[i]+1];
                // cout<<"ls "<<ls<<" rs "<<rs<<endl;
                res=max(res,1+ls+rs);
                m[nums[i]]=1+ls+rs;
                m[nums[i]-ls]=1+ls+rs;
                m[nums[i]+rs]=1+ls+rs;
            }
        }
        return res;
    }
};