class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string>res;
        if(s.size()<11)return res;
        map<string,pair<int,set<string>>>m;
        for(int i=0;i<s.size();i++)
        {
            string d=s.substr(i,10);
            m[d].first++;
            m[d].second.insert(s.substr(i,10));
        }
        for(auto i:m)
        {
            auto b= i.second;
            if(b.first>1)
            {
                auto d= b.second;
                for(auto j:d)res.push_back(j);
            }
        }
        return res;
    }
};