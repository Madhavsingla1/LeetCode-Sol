class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        st.push(path.substr(0,1));
        int i=1;
        while(i<path.size())
        {
            string j;
            while(i < path.size() and path[i]!='/')
                j+=path[i++];
            if(j=="..")
            {
               string d= st.top();
                st.pop();
                if(st.empty())
                    st.push(d);
                else
                    st.pop();
                i++;
                continue;
            }
            else if(j==""  or j=="." and st.top()=="/"){
                i++;
                continue;
            }
            st.push(j);
            st.push("/");
            i++;
        }
        string res;
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        return res.size()>1?res.substr(0,res.size()-1):res;
    }
};