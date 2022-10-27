class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>alive;
        for(int i=1;i<=n;i++)
            alive.push(i);
        while(alive.size()!=1)
        {
            int x = k;
            while(x>1)
            {
                int r = alive.front();
                alive.pop();
                alive.push(r);
                x--;
            }
            alive.pop();
        }
        return alive.front();
        
    }
};