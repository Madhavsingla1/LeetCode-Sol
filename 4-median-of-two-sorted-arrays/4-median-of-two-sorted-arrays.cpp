class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int size = nums1.size()+nums2.size();
        bool sz = size&1;
        int i=0,j=0,count=0;
        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                count++;
                if(count==(size+1)/2)
                {
                    if(sz)
                        return nums1[i];
                    else
                    {
                        if(i+1<nums1.size() and nums1[i+1]<nums2[j])
                            return (nums1[i]+nums1[i+1])/2.0;
                        else 
                            return (nums1[i]+nums2[j])/2.0;

                    }
                }
                i++;
            }
            else
            {
                count++;
                if(count==(size+1)/2)
                {
                    if(sz)
                    return nums2[j];
                    else
                    {
                        if(j+1<nums2.size() and nums1[i]>nums2[j+1])
                            return (nums2[j]+nums2[j+1])/2.0;
                        else 
                            return (nums2[j]+nums1[i])/2.0;

                    }
                }
                j++;
            }
                
        }
        while(i<nums1.size())
        {
            count++;
            if(count==(size+1)/2)
            {
                if(sz)return nums1[i];
                else return (nums1[i]+nums1[i+1])/2.0;
            }
            i++;
        }
        while(j<nums2.size())
        {
            count++;
            if(count==(size+1)/2)
            {
                if(sz)return nums2[j];
                else return (nums2[j]+nums2[j+1])/2.0;
            }
            j++;
        }
        return 0.0;
        
    }
};