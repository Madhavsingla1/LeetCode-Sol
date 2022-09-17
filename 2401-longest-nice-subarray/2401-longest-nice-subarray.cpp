class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        long long sumor=0;
        int res=1;
        int i=0,j=0;
        while(i<nums.size())
        {
            while((sumor&nums[i])!=0)
            {
                sumor^=nums[j++];
            }
            sumor|=nums[i];
            res = max(res,i-j+1);
            i++;
        }
        return res;
    }
};