class Solution {
public:
    int numSteps(string s) {
        if(s.size()==1)return 0;
        int res=0;
        s="0"+s;
        int d = s.size() - 1;
        while(d)
        {
            int count=0;
            while(s[d]=='1')
            {
                count++;
                d--;
            }
            if(count)
            {
                s[d]='1';
                res+=count;
            }
            else d--;
            res++;
        }
        if(s[2]=='0')res-=2;
        return res;
    }
};