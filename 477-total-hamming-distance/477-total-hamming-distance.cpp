class Solution {
public:
    int totalHammingDistance(vector<int>& nums) 
    {
        int res=0;
        long long mask = (1LL<<31);
        while(mask)
        {
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(mask&nums[i])count++;
            }
            res+=count*(nums.size()-count);
            mask>>=1;
        }
        return res;
        
    }
};