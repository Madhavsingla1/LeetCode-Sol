class Solution {
public:
    int partitionString(string s) 
    {
        int res=1;
        vector<int>vec(26,0);
        int i=0,j=0;
        while(j<s.size())
        {
            if(++vec[s[j]-'a']>1)
            {
                // cout<<j<<endl;
                res++;
                while(i<j)
                {
                    vec[s[i++]-'a']--;
                }
            }
            j++;
        }
        return res;
        
    }
};