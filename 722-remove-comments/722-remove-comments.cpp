class Solution {
public:
    vector<string> removeComments(vector<string>& s) {
        vector<string>res;
        bool com=1;
        string a="";
        for(int i=0;i<s.size();i++)
        {
            if(com)a="";
            for(int j=0;j<s[i].size();j++)
            {
                if(com){
                    if(s[i][j]=='/')
                    {
                        if(s[i][j+1]=='/')break;
                        else if(s[i][j+1]=='*')
                        {
                            j+=2;
                            com=0;
                            while(j<s[i].size())
                            {
                                if(j+1<s[i].size() and s[i][j]=='*' and s[i][j+1]=='/')
                                {
                                    com=1;
                                    j++;
                                    break;
                                }
                                j++;
                            }
                        }
                        else a+=s[i][j];
                    }
                    else
                        a+=s[i][j];
                }
                else
                {
                    while(j<s[i].size())
                    {
                        if(j+1<s[i].size() and s[i][j]=='*' and s[i][j+1]=='/')
                        {
                            com=1;
                            j++;
                            break;
                        }
                        j++;
                    }
                }
            }
            if(a.size() and com)res.push_back(a);
        }
        return res;
    }
    
};