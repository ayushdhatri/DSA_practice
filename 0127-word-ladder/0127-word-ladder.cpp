class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        for(auto x: wordList)
        {
            s.insert(x);
        }
        queue<pair<string, int>>q;
        q.push({beginWord,1});
        int ans = 0;
        while(q.size()!=0)
        {
            string temp = q.front().first;
            int seq = q.front().second;
            q.pop();
            if(temp==endWord)
            {
                ans = seq;
                break;
            }
            
            for(int i=0;i<temp.size();i++)
            {
                char word = temp[i];
                for(char ch='a';ch<='z';ch++)
                {
                    temp[i]=ch;
                    if(s.find(temp)!=s.end())
                    {
                        q.push({temp, seq+1});
                        s.erase(temp);
                    }
                }
                temp[i]=word;
            }
        }
        return ans;
        
    }
};