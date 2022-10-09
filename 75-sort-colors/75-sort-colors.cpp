class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        // vector<int>c(3,0);
        // for(int i=0;i<nums.size();i++)
        //     c[nums[i]]++;
        // int i=0,k=0;
        // while(i<nums.size())
        // {
        //     while(c[k])
        //     {
        //         nums[i]=k;
        //         i++;
        //         c[k]--;
        //     }
        //     k++;
        // }
        
        int a=0,b=nums.size()-1,c=0;
        while(c<=b)
        {
            if(nums[c]==0){
                swap(nums[c],nums[a]);
                a++;
            }
            else if(nums[c]==2){
                swap(nums[c],nums[b]);
                b--;
                c--;
            }
            c++;
        }
    }
};