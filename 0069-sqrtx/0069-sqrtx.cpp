class Solution {
public:
    int mySqrt(int x) {
        long long int low = 0;
        long long int high = x;
        long long ans = 0;
        while(low<=high)
        {
            long long int mid = low + (high-low)/2;
            long long int temp = mid*mid;
            if(temp==x)
                return mid;
            else if(temp>x)
            {
                high = mid-1;
                
            }
            else
            {
                ans = mid;
                low = mid+1;
            }
            
        }
        return ans;
        
    }
};