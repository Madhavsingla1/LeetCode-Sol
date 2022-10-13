class Solution {
public:
    int minSwaps(string s) 
    {
        stack<char>st;
        for(auto i:s)
        {
            if(st.empty())st.push(i);
            else if(st.top()=='[' and i==']')st.pop();
            else st.push(i);
        }
        int d= st.size()/2;
        return (d+1)/2;
    }
};