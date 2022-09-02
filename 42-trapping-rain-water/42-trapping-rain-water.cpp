class Solution {
public:
    int trap(vector<int>& height) {
//         long long n = height.size();
//         vector<int>pm(n),sm(n);
//         pm[0]=height[0];
        
//         for(int i=1;i<n;i++)
//             pm[i]=max(pm[i-1],height[i]);
        
//         sm[n-1]=height[n-1];
        
//         for(int i=n-2;i>=0;i--)
//             sm[i]=max(sm[i+1],height[i]);
        
//         int res = 0;
//         for(int i=1;i<n-1;i++)
//         {
//             int decide = min(pm[i-1],sm[i+1]);
//             if(decide>height[i])
//                 res+=decide-height[i];
//         }
//         return res;
        
        int res=0;
        int rm = height[height.size()-1],lm = height[0];
        int i=0,r=height.size()-1;
        while(i<r)
        {
            if(lm<=rm)
            {
                i++;
                lm = max(lm,height[i]);
                res+=lm-height[i];
            }
            else
            {
                r--;
                rm = max(rm,height[r]);
                res+=rm - height[r];
            }
        }
        return res;
        
    }
};