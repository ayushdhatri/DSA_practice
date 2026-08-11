#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    // Memoization table: (num, den, idx) -> count
    map<pair<pair<ll, ll>, int>, int>dp;

public:
    int countSequences(vector<int>& nums, long long k) {
        return solve(0, 1, 1, k, nums);
    }

    int solve(int idx, long long num, long long den, long long k, const vector<int>& nums) {
        long long g = std::gcd(num, den);
        num /= g;
        den /= g;
        // Base Case: check if reduced fraction equals k without multiplication overflow
        if (idx == nums.size()) {
            if(num % den == 0 && num / den == k) return 1;
            return 0;
        }

        // 1. Simplify fraction using GCD to collapse states and keep numbers small
       

        // 2. Cache Check
        auto key = make_pair(make_pair(num, den), idx);
        if (dp.count(key)) return dp[key];

        // 3. Transitions
        int count = solve(idx + 1, num, den, k, nums);                  // Unchanged
        count += solve(idx + 1, num * nums[idx], den, k, nums);         // Multiply
        count += solve(idx + 1, num, den * nums[idx], k, nums);         // Divide

        // 4. Save and Return
        return dp[key] = count;
    }
};