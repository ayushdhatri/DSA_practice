class Solution {
public:
    string subString(int start, int end, string &word){
        string temp = "";
        for(int i = start;i<=end;i++){
            temp+=word[i];
        }
        return temp;
        
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int>freq;
        int n = dictionary.size();
        int m = sentence.size();
        for(int i = 0;i<n;i++){
            freq[dictionary[i]]+=1;
        }
        vector<string>words;
        int i = 0;
        string temp = "";
        while(i<m){
            if(sentence[i]!=' '){
                temp+=sentence[i];
            }
            else{
                words.push_back(temp);
                temp="";
            }
            i++;
        }
        words.push_back(temp);
        for(int i = 0;i<words.size();i++){
            string substr = "";
            for(int j = 0;j<words[i].size();j++){
               substr+=(words[i][j]);
                if(freq.find(substr)!=freq.end()){
                    words[i]=substr;
                    break;
                }
            }
        }
        string ans = "";
        for(auto x: words){
            ans+=(x+" ");
        }
        ans.pop_back();
        return ans;
    }
};