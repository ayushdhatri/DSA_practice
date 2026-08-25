class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we can apply L , R DP?
        // see if I buy a stock on day I can sell it on next i +1 till N days, and choose one which has maximum
        // if that maximum is less than this arr[i] then its a loss deal
        // if that maximum is high then arr[i] then its a profit deal so take it and find such maximmum;
        int n = prices.size();
        int maxAns = 0;
        int maxValueSoFar = prices[n-1];
        for(int i = n-2;i>=0;i--){
            if(prices[i] < maxValueSoFar){
                maxAns = max(maxAns, maxValueSoFar - prices[i]);
            }
            else{
                // we will have negative or zero value
                // since we cannot take negative so lets take zero
                maxAns = max(maxAns, 0);
            }
            maxValueSoFar = max(maxValueSoFar, prices[i]);
        }
        cout<<maxAns<<endl;
        return maxAns;
        
        
    }
};