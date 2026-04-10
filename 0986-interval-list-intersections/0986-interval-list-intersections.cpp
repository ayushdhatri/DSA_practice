class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // Event format: pair<coordinate, type>
        // type: 0 for "start", 1 for "end"
        vector<pair<int, int>> events;
        
        for (const auto& interval : firstList) {
            events.push_back({interval[0], 0}); // +1 to active count
            events.push_back({interval[1], 1}); // -1 to active count
        }
        for (const auto& interval : secondList) {
            events.push_back({interval[0], 0});
            events.push_back({interval[1], 1});
        }
        
        // Sort events. 
        // If coordinates match, type '0' (start) comes before type '1' (end).
        sort(events.begin(), events.end());
        
        vector<vector<int>> result;
        int active = 0;
        int start_intersect = -1;
        
        for (const auto& event : events) {
            if (event.second == 0) { // It's a start event
                active++;
                if (active == 2) {
                    // Both lists have an active interval here
                    start_intersect = event.first; 
                }
            } else { // It's an end event
                if (active == 2) {
                    // The overlap just finished
                    result.push_back({start_intersect, event.first});
                }
                active--;
            }
        }
        
        return result;
    }
};