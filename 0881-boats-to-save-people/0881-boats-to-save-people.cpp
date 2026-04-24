class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // STEP 1: Counting Sort O(N + K)
        // Count the frequencies
        vector<int> count(limit + 1, 0);
        for (int weight : people) {
            count[weight]++;
        }
        
        // Rebuild the people array in sorted order
        int index = 0;
        for (int weight = 1; weight <= limit; weight++) {
            while (count[weight] > 0) {
                people[index] = weight; // Overwrite the original array
                index++;
                count[weight]--;
            }
        }
        
        // STEP 2: Your original Two-Pointer logic! O(N)
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--; 
            }
            boats++;
        }
        
        return boats;
    }
};