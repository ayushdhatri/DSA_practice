class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        string a ="";
        string b = "";
        int n = s.size();
        int c1=0,c2=0;
        for(int i=0;i<n/2;i++) {
            a+=s[i];
            if(isVowel(s[i]))
                c1++;
        }
        for(int j=n/2;j<n;j++){
            b+=s[j];
            if(isVowel(s[j]))
                c2++;
        }
        return c1==c2;
        
        
    }
};