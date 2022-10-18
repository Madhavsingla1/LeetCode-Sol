class Solution {
public:
    string countAndSay(int n) 
    {
        n--;
        string res="1";
        while(n--)
        {
            string d;
            int s=1;
            for(int i=1;i<res.size();i++)
            {
                if(res[i]==res[i-1])s++;
                else{
                    d+=(s+'0');
                    d+=res[i-1];
                    s=1;
                }
            }
            d+=(s+'0');
            d+=res[res.size()-1];
            res=d;
        }
        return res;
    }
};