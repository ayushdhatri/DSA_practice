class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        unordered_map<string,int> dp;
        int ans = 1;

        for (auto &w : words) {
            int best = 1;

            for (int i = 0; i < (int)w.size(); i++) {
                string pred = w.substr(0, i) + w.substr(i + 1);

                if (dp.count(pred)) {
                    best = max(best, dp[pred] + 1);
                }
            }

            dp[w] = best;
            ans = max(ans, best);
        }

        return ans;
    }
};
