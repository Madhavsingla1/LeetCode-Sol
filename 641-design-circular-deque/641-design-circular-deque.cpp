class MyCircularDeque {
public:
    vector<int>vec;
    int f,l,mx;
    MyCircularDeque(int k) {
        vec.resize(k,-1);
        f=-1,l=k-1,mx=k;
    }
    
    bool insertFront(int value) {
        // cout<<1<<endl;
        if(isFull())return false;
        if(f==-1)f++;
        vec[f++]=value;
        return true;
    }
    
    bool insertLast(int value) {
        // cout<<2<<endl; 
        if(isFull())return false;
        vec[l--]=value;
        return true;
        
    }
    
    bool deleteFront() {
        // cout<<3<<endl;
        if(isEmpty())return false;
        if(f==-1)
        {
            for(int i=mx-1;i>l+1;i--)
            {
                vec[i]=vec[i-1];
            }
            l++;
        }
        else f--;
        if(f==0)f=-1;
        return true;
    }
    
    bool deleteLast() {
        // cout<<4<<endl;
        if(isEmpty())return false;
        if(l==mx-1)
        {
            for(int i=0;i<f-1;i++)
            {
                vec[i]=vec[i+1];
            }
            f--;
            if(f==0)f=-1;
        }
        else l++;
        return true;
        
    }
    
    int getFront() {
        // cout<<5<<endl;
        int d=-1;
        if(f==-1 and l==mx-1)return d;
        else if(f!=-1)
            d=vec[f-1];
        else d=vec[mx-1];
        return d;
    }
    
    int getRear() {
        // cout<<6<<endl;
        int d=-1;
        if(f==-1 and l==mx-1)return d;
        else if(l!=mx-1)
            d=vec[l+1];
        else d=vec[0];
        return d;
    }
    
    bool isEmpty() {
        return f==-1 and l==mx-1;
    }
    
    bool isFull() {
        // cout<<8<<endl;
        return !(f<=l);
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */