class Solution {
public:
    struct manachar {
        vector<int> p;

        void run_manachar(string t) {

            int n = t.size();

            p.assign(n, 1);

            int l = 1, r = 1;

            for (int i = 1; i < n; i++) {
                if(r > i){
                    p[i] = max(0, min(r - i, p[r-i+l]));
                }
                while (i - p[i] >= 0 && i + p[i] < n &&
                       t[i - p[i]] == t[i + p[i]]) {

                    p[i]++;
                }

                if (i + p[i] > r) {

                    l = i - p[i];

                    r = i + p[i];
                }
            }
        }

        void build(string s) {

            string t;

            for (auto x : s) {

                t += (string("#") + x);
            }

            run_manachar(t + "#");
        }

        int getLongest(int cen, bool odd){
            int pos = 2* cen + 1+ !odd;
            return p[pos] - 1;
        }

        // Drastically simplified O(1) query
        bool isPalindrome(int l, int r) {
            if(r-l+1<= getLongest((l+r)/2, l%2== r%2)){
                return 1;
            }
            return 0;
        }
    } m;

    bool checkPartitioning(string s) {
        int n = s.size();

        // You MUST build the manacher array first!
        m.build(s);

        for (int i = 0; i < n - 2; i++) {
            // Check first segment: s[0...i]
            // Use continue, NOT break! We just want to skip this 'i', not stop
            // the loop
            if (!m.isPalindrome(0, i))
                continue;

            for (int j = i + 1; j < n - 1; j++) {
                // Check second segment: s[i+1...j]
                if (!m.isPalindrome(i + 1, j))
                    continue;

                // Check third segment: s[j+1...n-1]
                int k = j + 1;
                if (k < n && m.isPalindrome(k, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};