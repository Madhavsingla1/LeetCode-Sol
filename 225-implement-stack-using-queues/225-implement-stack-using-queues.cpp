class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x);
    }
    
    int pop() {
        queue<int>tmp;
        while(q.size()>1)
        {
            tmp.push(q.front());
            q.pop();
        }
        int d= q.front();
        q.pop();
        q=tmp;
        return d;
    }
    
    int top() {
       return q.back();
    }
    bool empty() { 
        // cout<<q.size()<<endl;
        return !q.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */