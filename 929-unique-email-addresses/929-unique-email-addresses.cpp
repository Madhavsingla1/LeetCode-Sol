class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        set<string>st;
        for(auto i:emails)
        {
            string s;
            int flag=1;
            for(int j=0;j<i.size();j++)
            {
                if(i[j]=='.' and flag!=2)continue;
                else if(i[j]=='+')flag=0;
                else if(i[j]=='@')flag=2;
                if(flag!=0)s+=i[j];
            }
            // cout<<s<<endl;
            st.insert(s);
        }
        return st.size();
    }
};