class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int currmax= nums[0],possible = nums[0];
        int res=1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<currmax)
            {
                res=i+1;
                currmax= possible;
            }
            else 
            {
                possible =max(possible,nums[i]);
            }
        }
        return res;
        
    }
};