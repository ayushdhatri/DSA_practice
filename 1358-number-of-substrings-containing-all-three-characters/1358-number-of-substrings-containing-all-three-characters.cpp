class Solution {
public:
    bool exactone(vector<int>&arr)
    {
        if(arr[0]==1&&arr[1]==1&&arr[2]==1)
            return true;
        return false;
        
    }
    bool atleastone(vector<int>&arr)
    {
       if(arr[0]==0||arr[1]==0||arr[2]==0)
           return false;
        return true;
        
    }
    int numberOfSubstrings(string s) {
        vector<int>arr(26,0);
        int i=0,j=0;
        int n = s.size();
        int count=0;
        while(j<n)
        {
            arr[s[j]-'a']++;
            if(atleastone(arr)==false)
                j++;
            else
            {
                
                while(atleastone(arr)!=false)
                {
                    count+=(n-j);
                    arr[s[i]-'a']--;
                    i++;
                }
                
                j++;
            }
        }
        return count;
        
        
    }
};