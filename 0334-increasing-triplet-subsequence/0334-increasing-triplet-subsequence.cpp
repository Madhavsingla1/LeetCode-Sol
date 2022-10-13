class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int b, a=b=INT_MAX;
        for(auto i:nums)
        {
            if(i<=a)a=i;
            else if(i<=b)b=i;
            else return true;
        }
        return false;
        
    }
};