class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>>line;
        int n = tickets.size();
        for(int i=0;i<n;i++)
            line.push({tickets[i],i});
        int time=0;
        while(line.size()!=0)
        {
            time++;
            int top = line.front().first;
            int pos = line.front().second;
            top--;
            line.pop();
            if(pos==k&&top==0)
                return time;
            if(top!=0)
                line.push({top, pos});
        }
        return 0;
        
        
        
    }
};