class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) 
    {
        int res=1;
        vector<pair<int,int>>vec;
        for(int i=0;i<p.size();i++)
            vec.push_back({p[i],s[i]});
        
        sort(vec.begin(),vec.end(),greater<>());
        double prevt = (double)(t-vec[0].first)/vec[0].second;
        for(int i=1;i<vec.size();i++)
        {
            double currt = (double)(t-vec[i].first)/vec[i].second;
            if(currt>prevt){
                res++;
                prevt=currt;
            }
        }
        return res;
        
    }
};