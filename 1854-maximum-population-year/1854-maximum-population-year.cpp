class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int>year(110,0);
        for(int i = 0;i<logs.size();i++){
            int birth = logs[i][0]-1950;
            int death = logs[i][1]-1950;
            year[birth]+=1;
            year[death]-=1;
        }
        for(int i = 1;i<year.size();i++){
            year[i]+=year[i-1];
        }
        int ans = INT_MIN;
        int index = -1;
        for(int i = 0;i<year.size();i++){
            cout<<year[i]<<"->"<<i + 1950<<endl;
            if(year[i] > ans){
                ans = year[i];
                index = i;

            }
        }
        cout<<endl;
        return (index + 1950);


        
    }
};