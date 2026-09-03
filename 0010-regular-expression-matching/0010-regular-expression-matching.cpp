class Solution {
public:
    int dp[25][25];

    bool rec(int i, int j, const string &s, const string &p) {
        // Base Case: If pattern is completely used up,
        // it only matches if the string is also completely consumed.
        if (j == p.size()) {
            return i == s.size();
        }

        // Cache Check
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Check if the current character matches (Scenario: single character match)
        // 1. We must have characters left in s (i < s.size())
        // 2. Either the characters are identical, or pattern has '.'
        bool first_match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');

        bool ans = false;

        // Lookahead: Check if next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Choice 1: Use 0 times -> Skip the token "[char]*" entirely (advance j by 2)
            // Choice 2: Use 1+ times -> If first character matches, consume one from s (advance i by 1, stay at j)
            ans = rec(i, j + 2, s, p) || (first_match && rec(i + 1, j, s, p));
        } else {
            // Standard single character match -> Advance both pointers
            ans = first_match && rec(i + 1, j + 1, s, p);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, s, p);
    }
};