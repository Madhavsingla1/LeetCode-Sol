class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0,n=chalk.size();
        for(int i=0;i<n;i++)
        {
            if(chalk[i]>k-sum)
            {
                return i;
            }
            sum+=chalk[i];
        }
        k%=sum;
        int res=0;
        sum=0;
        for(int i=0;i<n;i++)
        {
            // cout<<k-sum<<endl;
            // cout<<chalk[i]<<endl;
            if(chalk[i]>k-sum)
            {
                res=i;
                break;
            }
            sum+=chalk[i];
        }
        return res;
    }
};