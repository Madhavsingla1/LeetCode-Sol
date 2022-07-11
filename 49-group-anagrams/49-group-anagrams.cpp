class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string d= strs[i];
            sort(d.begin(),d.end());
            m[d].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++)
        {
            string d= strs[i];
            sort(d.begin(),d.end());
            if(m.find(d)!=m.end())
            {
                res.push_back(m[d]);
                m.erase(d);
            }
        }
        return res;
    }
};