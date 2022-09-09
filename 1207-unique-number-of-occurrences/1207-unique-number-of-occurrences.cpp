class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        set<int>st;
        int count=1;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                if(st.find(count)!=st.end())
                {
                    cout<<count<<endl;
                    return false;
                }
                else st.insert(count);
                count=0;
            }
            count++;
        }
        if(st.find(count)!=st.end())
            return false;
        return true;
        
    }
};