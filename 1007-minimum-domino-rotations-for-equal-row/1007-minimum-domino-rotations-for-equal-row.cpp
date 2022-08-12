class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottom) 
    {
        int n= tops.size();
        int res=n+1;
        for(int i=1;i<7;i++)
        {
            if(i==tops[0] or i==bottom[0])
            {
                int a=0,b=0;
                // cout<<i<<endl;
                bool valid=true;
                for(int j=0;j<tops.size();j++)
                {
                    if(tops[j]==i)a++;
                    if(bottom[j]==i)b++;
                    if(tops[j]!=i and bottom[j]!=i){
                        // cout<<tops[i]<<bottom[j]<<endl;
                        valid=false;break;}
                }
                cout<<valid<<endl;
                if(valid)
                {
                    res=min({res,n-a,n-b});
                }
            }
        }
        if(res==n+1)
        {
            res=-1;
        }
        return res;
        
    }
};