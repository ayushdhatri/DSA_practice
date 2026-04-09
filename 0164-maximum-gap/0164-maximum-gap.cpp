class Solution {
public:
   int maximumGap(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0; // Return 0 instead of void

    int lo = *min_element(arr.begin(), arr.end());
    int hi = *max_element(arr.begin(), arr.end());
    int range = hi - lo;

    if (range == 0) return 0;   // all elements are equal, max gap is 0

    // CHANGE 1: Replace 2D vector with two 1D vectors for O(N) space
    vector<int> bucketMin(n, INT_MAX);
    vector<int> bucketMax(n, INT_MIN);

    // Normalize: map [lo, hi] → bucket index [0, n-1]
    for (int i = 0; i < n; i++) {
        // Your exact formula!
        int bi = (int)((double)(arr[i] - lo) / range * (n - 1));
        
        // CHANGE 2: No push_back. Just track the boundaries.
        bucketMin[bi] = min(bucketMin[bi], arr[i]);
        bucketMax[bi] = max(bucketMax[bi], arr[i]);
    }

    // CHANGE 3: Delete sorting. Calculate max gap directly.
    int maxGap = 0;
    int prevMax = lo;
    
    for (int i = 0; i < n; i++) {
        if (bucketMin[i] == INT_MAX) continue; // skip empty buckets
        
        maxGap = max(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }
    
    return maxGap;
}
};