class CustomStack {
public:
    vector<int>vec;
    int vall=-1;
    int mx;
    CustomStack(int maxSize) {
        vec.resize(maxSize,-1);
        mx=maxSize;
    }
    
    void push(int x) {
        if(vall<mx-1){
                  vall++;
        vec[vall]=x;}
    }
    
    int pop() {
        int d=-1;
        if(vall!=-1){
            d=vec[vall];
            vec[vall]=-1;
            vall--;
        }
        return d;
    }
    
    void increment(int k, int val) {
        int d= k;
        if(k>=vall+1)d=vall+1;
        for(int i=0;i<d;i++){
            // cout<<vec[i]<<endl;
            vec[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */