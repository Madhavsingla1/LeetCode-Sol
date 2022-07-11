class Solution {
public:
    int gcd(int x,int y)
    {
        if(x==0)return y;
        else if(y==0)return x;
        int mx = max(x,y),mn= min(x,y);
        return gcd(mx%mn,mn);
    }
    void standr(double &a,double &b)
    {
        if(a==0)b=1;
        else if(b==0)a=1;
        else if((a<0 and b<0) or b<0)
        {
            a*=-1,b*=-1;
        }
    }
    int maxPoints(vector<vector<int>>& p) 
    {
        int res=0;
        for(int i=0;i<p.size();i++)
        {
            map<pair<double,double>,int>m;
            int count=0,mx=0;
            for(int j=i+1;j<p.size();j++)
            {
                if(p[i][0]==p[j][0] and p[i][1]==p[j][1])
                    count++;
                else
                {
                    int x = p[i][1]-p[j][1],y=p[i][0]-p[j][0];
                    int d = gcd(abs(x),abs(y));
                    double f = x/d,s = y/d;
                    standr(f,s);
                        m[{f,s}]++;
                    mx = max(mx, m[{f,s}]);
                }
            }
            res=max(res,1+count+mx);
        }
        return res;
    }
};