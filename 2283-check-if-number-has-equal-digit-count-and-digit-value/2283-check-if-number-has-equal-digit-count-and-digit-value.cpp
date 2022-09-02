class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int>mp;
        for(int i=0;i<num.size();i++)
            mp[num[i]]++;
        // for(auto i:mp)
        //     cout<<i.first<<" "<<i.second<<endl;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]-'0'!=mp[i+'0']){
                return false;}
        }
        return true;
    }
};