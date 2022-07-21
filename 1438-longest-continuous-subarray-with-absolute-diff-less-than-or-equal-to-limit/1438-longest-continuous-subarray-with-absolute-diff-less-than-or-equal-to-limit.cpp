class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n=nums.size(),res=1,i=0,j=0;
        deque<int>l,s;
        while(j<n)
        {
            while(!l.empty() and nums[l.back()]<nums[j])
                l.pop_back();
            l.push_back(j);
            while(!s.empty() and nums[s.back()]>nums[j])
                s.pop_back();
            s.push_back(j);
            
            // cout<<nums[l.front()]<<" "<<nums[s.front()]<<endl;
            if(nums[l.front()]-nums[s.front()]<=limit)
            {
                // cout<<j<<i<<endl;
                res=max(res,j-i+1);
            }
            else
            {
                while(!l.empty()  and !s.empty() and nums[l.front()]-nums[s.front()]>limit)
                {
                   if(!l.empty() and l.front()==i)l.pop_front();
                    if(!s.empty() and s.front()==i)s.pop_front();
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};