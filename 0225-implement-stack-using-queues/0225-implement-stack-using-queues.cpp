class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    int size;
    MyStack() {
        size=0;
        
    }
    
    void push(int x) {
        if(q1.size()==0) {
            q1.push(x);
            size++;
            return;
        }
        while(q1.size()!=0)
        {
            int data = q1.front();
            q2.push(data);
            q1.pop();
        }
        q1.push(x);
        while(q2.size()!=0)
        {
            int data = q2.front();
            q1.push(data);
            q2.pop();
        }
        size++;
        return;
    }
    
    int pop() {
        if(size==0){
            size--;
            return -1;
        }
        int data  = q1.front();
        q1.pop();
        size--;
        return data;
    }
    
    int top() {
        if(q1.size()!=0)
          return q1.front();
        return -1;
        
    }
    
    bool empty() {
        return size==0;
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