#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct manachar {
        vector<int> p;

        void runManachar(string t) {
            int n = t.size();
            p.assign(n, 1);
            int l = 1, r = 1;

            for (int i = 1; i < n; i++) {
                if(i < r)
                    p[i] = max(0, min(r - i, p[r - i + l]));

                // BUG FIX 1: Use 'while' instead of 'if'
                // BUG FIX 2: Correct lower bound check to (i - p[i] >= 0)
                while (i - p[i] >= 0 && i + p[i] < n && t[i + p[i]] == t[i - p[i]]) {
                    p[i]++;
                }

                if (i + p[i] > r) {
                    l = i - p[i];
                    r = i + p[i];
                }
            }
        }

        // BUG FIX 3: Change return type from void to vector<int>
        vector<int> build(string s) {
            // BUG FIX 4: Properly interleave characters with '#'
            string t="";
            for(auto x: s)
            {
                t+=(string("#") + x);
            }
            runManachar(t+"#");
            return this->p;
        }
    };

    string longestPalindrome(string s) {
      

        manachar m1;
        vector<int> manArr = m1.build(s);
        cout<<manArr.size()<<endl;
        int max_radius = 0;
        int centerIndex = 0;

        // Find center index with the maximum radius
        for (int i = 0; i < manArr.size(); i++) {
            if (manArr[i] > max_radius) {
                max_radius = manArr[i];
                centerIndex = i;
            }
        }

        // Length of palindrome in original string
        int max_len = max_radius - 1;

        // Formula to convert index from transformed string 't' back to original string 's'
        int startIndex = (centerIndex - max_len) / 2;
        cout<<startIndex<<" "<<max_len;
        return s.substr(startIndex, max_len);
    
    }
};