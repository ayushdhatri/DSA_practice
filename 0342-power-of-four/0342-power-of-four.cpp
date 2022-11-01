class Solution {
public:
    bool isit(int n)
    {
        if(n<1)
            return false;
        if(n==1)
            return true;
        return (n%4==0)&&isit(n/4);
    }
    bool isPowerOfFour(int n) {
        return isit(n);
        
    }
};