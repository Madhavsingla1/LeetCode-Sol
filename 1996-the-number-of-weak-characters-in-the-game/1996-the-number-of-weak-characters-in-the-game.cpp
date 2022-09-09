class Solution {
    // int res=0;
public:
    // void mergesort(int l,int mid, int r,vector<vector<int>>&prop)
    // {
    //     int i=l,j=mid+1;
    //     vector<vector<int>>ac;
    //     while(i<=mid and j<=r)
    //     {
    //         if(prop[i][0]<prop[j][0] and prop[i][1]<prop[j][1])
    //         {
    //             res++;
    //             ac.push_back(prop[i]);
    //             i++;
    //         }
    //         else if(prop[j][1]<prop[i][1] and prop[j][0]<prop[i][0])
    //         {
    //             res++;
    //             ac.push_back(prop[j]);
    //             j++;
    //         }
    //         else
    //         {
    //             ac.push_back(prop[i]);
    //             i++;
    //         }
    //     }
    //     while(i<=mid)
    //     {
    //         ac.push_back(prop[i]);
    //         i++;
    //     }
    //     while(j<=r)
    //     {
    //         ac.push_back(prop[j]);
    //         j++;
    //     }
    //     for(int i=l;i<=r;i++)
    //     {
    //         prop[i]=ac[i-l];
    //     }
    // }
    // void merge(int l,int r,vector<vector<int>>&prop)
    // {
    //     if(l>=r)return;
    //     int mid = (l+r)/2;
    //     merge(l,mid,prop);
    //     merge(mid+1,r,prop);
    //     return mergesort(l,mid,r,prop);
    // }
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) 
    {
        // merge(0,prop.size(),prop);
        sort(prop.begin(),prop.end(),comp);
        int res=0;
        int mx =INT_MIN;
        for(int i=prop.size()-1;i>=0;i--)
        {
           if(prop[i][1]<mx)res++;
            mx= max(mx,prop[i][1]);
        }
        return res;
    }
};