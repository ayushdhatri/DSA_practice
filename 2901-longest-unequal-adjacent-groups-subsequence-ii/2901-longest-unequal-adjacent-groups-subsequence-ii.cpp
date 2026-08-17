class Solution {
public:
int ls[1010];
bool findHamming(string &word1, string &word2){
    if(word1.size() != word2.size())return false;
    int count = 0;
    for(int i = 0;i<word1.size();i++){
        if(word1[i] != word2[i])count+=1;
    }
    return count == 1;
}
int rec(int level, vector<string>& words, vector<int>&groups){
    // pruning
    if(level < 0)return 0;
    // base case
    // cache
    if(ls[level] != -1)return ls[level];
    // transition
    int ans = 1;
    for(int i = level -1;i>=0;i--){
        string temp = words[i];
        if(groups[level] != groups[i] && findHamming(words[level], temp)){
            ans = max(ans,1 +  rec(i, words, groups));
        }
    }
    // save and return
    return ls[level] = ans;
}

void printls(int level, vector<string>&words, vector<int>&groups, vector<string>&ans){
    // pruning 

    // base case
    if(ls[level] == 1){
        ans.push_back(words[level]);
        return;
    }
    ans.push_back(words[level]);
    // transition
    for(int i = level -1;i>=0;i--){
            string temp = words[i];
            if(groups[level] != groups[i] && findHamming(words[level], temp) && ls[i] == ls[level]-1){
                // we got other word
                printls(i, words, groups, ans);
                break;
                
            }
    }


    // save and return 
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        //my understanding:
        // from the given words, we need the longest subsequence satsifying the condition:
        // 1) adjacent words should not have equal group length
        // 2) adjancent words should be of equal lenght and hamming distance bewteen them is 1:
        //        -> which means 
        // I will solve it using form 2
        // first we will find the ls[] = here ls[i] represent longest subsequence with condition
        // similary we can find all the ls[i] where i>=0 && i <=n-1.
        // Here onward means we also need to have words prininted
        // now we need to do reverse engineering to get list of words
        int n = words.size();
        memset(ls,-1,sizeof(ls));
        int maxLen = 1;
        for(int i = n-1;i>=0;i--){
            maxLen =  max(maxLen, rec(i,words, groups));
        }
        cout<<maxLen;
        // now we have to print the answer
        vector<string>ans;
        for(int i = 0;i<n;i++){
            if(ls[i] == maxLen){
                // here our answer ends
                // from here traverse back and push the answer
                printls(i, words, groups, ans);
                break;

            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // here onwards we need the printing strategy
    }
};