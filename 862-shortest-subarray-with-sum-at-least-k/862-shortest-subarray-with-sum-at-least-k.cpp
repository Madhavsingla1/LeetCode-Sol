class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<long long>vec(n+1);
        vec[0]=0;
        for(int i=0;i<n;i++)
            vec[i+1]+=nums[i]+vec[i];
        deque<int>q;
        int res=INT_MAX;
        q.push_back(0);
        for(int i=1;i<=n;i++)
        {
            while(!q.empty() and vec[q.back()]>=vec[i])
                q.pop_back();
            while(!q.empty() and vec[i]-vec[q.front()]>=k)
            {
                res=min(res,i-q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
          while(!q.empty() and vec[q.back()]-vec[q.front()]>=k)
            {
                res=min(res,q.back()-q.front());
                q.pop_front();
            }
        return res==INT_MAX?-1:res;
    }
};