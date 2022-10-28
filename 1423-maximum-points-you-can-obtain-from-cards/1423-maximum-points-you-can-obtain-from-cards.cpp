class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalsum=0;
        int n = cardPoints.size();
        for(int i=0;i<n;i++)
            totalsum+=cardPoints[i];
        if(k==n)
            return totalsum;
        int ws = n-k;
        int minsum=INT_MAX;
        int sum=0;
        int i=0, j=0;
        while(j<n)
        {
            sum+=cardPoints[j];
            if((j-i+1)<ws)
                j++;
            else if((j-i+1)==ws)
            {
                minsum = min(minsum, sum);
                sum-=cardPoints[i];
                i++;
                j++;
            }
        }
        return totalsum-minsum;
        
    }
};