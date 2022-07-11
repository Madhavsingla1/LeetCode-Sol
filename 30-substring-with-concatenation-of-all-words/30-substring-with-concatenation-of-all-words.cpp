class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int>res;
        int n=words.size(),m=words[0].size();
        if(s.length()<n*m)return res;
        map<string,int>w;
        for(auto i:words)w[i]++;
        for(int i=0;i<s.size()-n*m+1;i++)
        {
            map<string,int>mt;
            // cout<<"i"<<i<<endl;
            for(int j=i;j<i+n*m;j+=m)
            {
                mt[s.substr(j,m)]++;
                // cout<<"Sub "<<s.substr(j,m)<<endl;
                // cout<<"Map "<<mt[s.substr(j,m)]<<endl;
            }
            int flag =1;
            for(int j=0;j<n;j++)
            {
                if(mt.find(words[j])==mt.end() or w[words[j]]!=mt[words[j]])
                {
                    flag =0;
                    break;
                }
            }
            if(flag)res.push_back(i);
        }
        return res;
    }
};