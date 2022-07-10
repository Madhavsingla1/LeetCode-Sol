class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        vector<int>res;
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[i+j].push_back(nums[i][j]);
            }
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            auto d= i->second;
            for(int j=d.size()-1;j>=0;j--)
            {
                res.push_back(d[j]);
            }
        }
        return res;
        
    }
};