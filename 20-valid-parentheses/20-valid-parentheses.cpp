class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;
        for(auto i:s)
        {
            if(i==')')
            {
                if(st.empty() or st.top()!='(')return false;
                else st.pop();
            }
            else if(i=='}')
            {
                 if(st.empty() or st.top()!='{')return false;
                else st.pop();
            }
            else if(i==']')
            {
                 if(st.empty() or st.top()!='[')return false;
                else st.pop();
            }
            else st.push(i);
                
        }
        if(st.empty())return true;
        return false;
        
    }
};