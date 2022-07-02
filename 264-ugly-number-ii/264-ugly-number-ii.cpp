class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>vec(n);
        vec[0]=1;
        int a=0,b=0,c=0;
        for(int i=1;i<n;i++)
        {
            int d = min(vec[a]*2,min(vec[b]*3,vec[c]*5));
            vec[i]=d;
            if(d==vec[a]*2)a++;
            if(d==vec[b]*3)b++;
            if(d==vec[c]*5)c++;
        }
        return vec[n-1];
    }
};