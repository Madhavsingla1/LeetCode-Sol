class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
//         long long int count=0;
//         long long int sum=0;
//         for(long long int i=0;i<arr.size();i++)
//         {
//             for(long long int j=i;j<arr.size();j++)
//             {
//                 sum=sum+arr[j];
                
//                 if(sum%2!=0)
//                 {
//                     count++;
//                 }
                
//             }
//             sum=0;
//         }
//         int k=pow(10,9)+7;
//         return count%k;
            long long int temp[2] = { 1, 0 };
            long long int result = 0, val = 0;
            for (long long int i = 0; i <= arr.size()-1; i++) 
            {
                val = (val + arr[i]) % 2;
 
                temp[val]++;
            }
             int k=pow(10,9)+7;
 
            result = (temp[0]%k * temp[1]%k);
 
            return (result)%k;
    }
};