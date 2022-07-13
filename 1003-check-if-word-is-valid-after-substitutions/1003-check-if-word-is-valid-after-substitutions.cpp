class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            st.push(s[i]);
            stack<char>d;
            int count=0;
            string a;
            while(!st.empty() and count<3)
            {
                a=st.top()+a;
                d.push(st.top());
                st.pop();
                count++;
            }
            if(a!="abc")
            {
                while(!d.empty()){
                    st.push(d.top());
                    d.pop();
                }
            }
        }
        return st.empty();
        
    }
};