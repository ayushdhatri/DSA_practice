class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        string s1 = "Push";
        string s2 = "Pop";
        int eleindex = 1;
        for(int i =0;i<target.size();i++)
        {
            while(eleindex!=target[i])
            {
                ans.push_back(s1);
                ans.push_back(s2);
                eleindex++;
            }
            ans.push_back(s1);
            eleindex++;
            
        }
        
        return ans;
        
    }
};