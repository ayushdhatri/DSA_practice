class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26)
            return false;
        vector<bool>charr(26);
        for(int i=0;i<sentence.size();i++)
        {
            charr[sentence[i]-'a']=true;
        }
        for(int i=0;i<26;i++)
        {
            if(charr[i]==false)
                return false;
        }
        return true;
        
        
    }
};