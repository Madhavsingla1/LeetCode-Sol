class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>res;
        for(int i=0;i<min(k,(int)nums.size());i++)
        {
            while(!q.empty() and nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for(int i=k;i<nums.size();i++)
        {
            if(q.front()==i-k)q.pop_front();
            while(!q.empty() and nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
        
    }
};