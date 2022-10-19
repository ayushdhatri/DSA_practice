class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    int size;
    MyQueue() {
        size=0;
    }
    void push(int x) {
        if(size==0) {
            s1.push(x);
            size++;
            return;
        }
        while(s1.size()!=0)
        {
            int data = s1.top();
            s2.push(data);
            s1.pop();
        }
        s1.push(x);
        while(s2.size()!=0)
        {
            int data = s2.top();
            s1.push(data);
            s2.pop();
        }
        size++;
        return;
    }
    
    int pop() {
        if(size==0)
            return -1;
        int x = s1.top();
        s1.pop();
        size--;
        return x;
    }
    
    int peek() {
        return s1.top();
        
    }
    
    bool empty() {
        return size==0;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */