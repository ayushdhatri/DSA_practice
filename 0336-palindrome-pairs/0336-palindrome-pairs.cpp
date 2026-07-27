#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if s[left...right] is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;
        vector<vector<int>> result;

        // Map each word to its original index in O(N*K)
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int n = word.length(); // Fix 1: Fixed typo (.lenght() -> .length())

            for (int j = 0; j <= n; j++) {
                // Case 1: Left is palindrome -> reverse(Right) + Left + Right
                if (isPalindrome(word, 0, j - 1)) {
                    string rightRev = word.substr(j);
                    reverse(rightRev.begin(), rightRev.end());

                    if (wordMap.find(rightRev) != wordMap.end() && wordMap[rightRev] != i) {
                        result.push_back({wordMap[rightRev], i});
                    }
                }

                // Case 2: Right is palindrome -> Left + Right + reverse(Left)
                // Fix 2: Added 'j < n' guard to prevent duplicate pair checks when Right is empty
                if (j < n && isPalindrome(word, j, n - 1)) {
                    string leftRev = word.substr(0, j);
                    reverse(leftRev.begin(), leftRev.end());

                    // Fix 3: Added '!= wordMap.end()' iterator check
                    if (wordMap.find(leftRev) != wordMap.end() && wordMap[leftRev] != i) {
                        result.push_back({i, wordMap[leftRev]});
                    }
                }
            }
        }
        return result;
    }
};