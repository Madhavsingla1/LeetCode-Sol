class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        unordered_set<int>st;
        vector<int>res;
        for(int i=1;i<=9;i++)
        {
            queue<pair<int,int>>q;
            q.push({i,1});
            while(!q.empty())
            {
                auto d= q.front();
                q.pop();
                int m= d.first%10;
                if(m-k>=0)
                {
                    int a =d.first*10+m-k;
                    if(d.second+1!=n)q.push({a,d.second+1});
                    else st.insert(a);
                }
                if(m+k<=9)
                {
                    int a =d.first*10+m+k;
                    if(d.second+1!=n)q.push({a,d.second+1});
                    else st.insert(a);
                }
            }      
        }
        for(auto i :st)
        {
            res.push_back(i);
        }
        return res;
    }
};