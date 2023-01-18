class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> m1,m2;
        for(auto it : words1) m1[it]++;
        for(auto it : words2) m2[it]++;
        int count =0;
        for(auto it : m1){
            if(it.second == 1 && m2.find(it.first) != m2.end() && m2[it.first] == 1)
                count++;
        }
        return count;
    }
};