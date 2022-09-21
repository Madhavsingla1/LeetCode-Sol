class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) 
    {
        int sum=0;
        for(auto i:nums)
        {
            if(!(i&1))sum+=i;
        }
        vector<int>res;
        for(auto i:q)
        {
            int d= nums[i[1]];
            if((d+i[0])%2==0)
            {
                if(d%2!=0)sum+=d;
                sum+=i[0];
            }
            else if(d%2==0)
            {
                sum-=d;
            }
            nums[i[1]]+=i[0];
            res.push_back(sum);
        }
        return res;
    }
};