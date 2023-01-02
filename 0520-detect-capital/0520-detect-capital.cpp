class Solution {
public:
    bool detectCapitalUse(string word) {
        // there can be three cases:
        bool case1 = true, case2=true, case3=true;
        // checking for ccase 1:
        for(auto x: word)
        {
            if(x<65||x>90)
            {
                case1=false;
                break;
            }
            
        }
        if(word[0]<65||word[0]>90)
        {
            case3=false;
        }
        for(int i=1;i<word.size();i++)
        {
            if(word[i]<97||word[i]>122)
            {
                case3 = false;
                break;
            }
            
        }
         for(auto x: word)
        {
             if(x<97||x>122)
             {
                 case2=false;
                 break;
             }
        }
        
       
        return case1||case2||case3;
        
        
        
    }
};