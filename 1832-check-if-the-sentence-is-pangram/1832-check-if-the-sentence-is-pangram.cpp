class Solution {
public:
    bool checkIfPangram(string sen) {
        unordered_set<char>st(sen.begin(),sen.end());
        return st.size()==26;
    }
};