class MedianFinder {
public:
   
        priority_queue<int>left;
        priority_queue<int, vector<int>, greater<int>>right;

    
    void addNum(int num) {
        if(left.size()==0&&right.size()==0)
        {
            left.push(num);
        }
        else
        {
            if(right.size()!=0&&num>right.top())
                right.push(num);
            else
                left.push(num);
            if((left.size()-right.size())>1)
            {
                if(left.size()>right.size())
                {
                    right.push(left.top());
                    left.pop();
                }
                else
                {
                    left.push(right.top());
                    right.pop();
                }
            }
        }
        
    }
    
    double findMedian() {
        if(left.size()+right.size()==1)
            return left.top();
        if(left.size()==right.size())
        {
            return 1.0*(left.top()+right.top())/2;
        }
        if(left.size()>right.size())
            return left.top();
        return right.top();
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */