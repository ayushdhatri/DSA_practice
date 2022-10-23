class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int i =0;
        int j = 0;
        string t="";
        int count=0;
        while(j<s.size())
        {
            t+=s[j];
            if((j-i+1)<k)
                j++;
            else if((j-i+1)==k)
            {
                int value = stoi(t);
                if(value!=0&&num%value==0)
                    count++;
                t = t.substr(1);
                i++;
                j++;
            }
            
        }
        return count;
        
    }
};