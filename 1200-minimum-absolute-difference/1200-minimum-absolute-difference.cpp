class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>vec;
        int mn=INT_MAX;
        int n=arr.size();
        for(int i=1;i<n;i++)
            mn= min(mn,arr[i]-arr[i-1]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]==mn)
            {
                vec.push_back({arr[i-1],arr[i]});
            }
        }
        return vec;
    }
};