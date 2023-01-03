class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if(strs.size()==1)
            return 0;
        vector<vector<char>>mat;
        for(auto x: strs)
        {
            string temp = x;
            vector<char>t;
            for(int i=0;i<temp.size();i++)
            {
                t.push_back(temp[i]);
            }
            mat.push_back(t);
        }
        int count=0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[j-1][i]>mat[j][i])
                {
                    count++;
                    break;
                }
            }
        }
        
        
        
        return count;
        
        
    }
};