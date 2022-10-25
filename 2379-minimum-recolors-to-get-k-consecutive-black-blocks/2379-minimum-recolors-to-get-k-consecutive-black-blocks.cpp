class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n  = blocks.size();
        int ans = n;
        int i=0;
        int j=0;
        int cw=0;
        while(j<n)
        {
            if(blocks[j]=='W')
                cw++;
            if((j-i+1)<k)
                j++;
            else if((j-i+1)==k)
            {
                ans = min(ans, cw);
                if(blocks[i]=='W')
                    cw--;
                i++;
                j++;
            }
            
        } 
        return ans;
            
        
    }
};