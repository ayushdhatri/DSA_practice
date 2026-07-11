class Solution {
public:

struct manachar{
    vector<int>p;
    
    void run_manachar(string t){
        int n = t.size();
        p.assign(n, 1);
        int l = 1, r = 1;
        for(int i = 1;i<n;i++){
            
            if(r > i){
                p[i] = max(0, min(r-i, p[r-i+l]));
            }
            while(i - p[i]>=0 && i+p[i]<n && t[i-p[i]] == t[i + p[i]]){
                p[i]++;
            }
            if(i + p[i]> r){
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    vector<int> build(string s){
        string t;
        for(auto x : s){
            t+=string("#") + x;
        }
        run_manachar(t+"#");
        return this->p;
    }
}m;

static bool comp(pair<int, int>a, pair<int, int>b){
    if(a.second > b.second){
        return false;
    }
    else if(a.second == b.second){
        return a.first < b.first;
    }
    return true;
}
    int maxPalindromes(string s, int k) {
        vector<int> manCharArr = m.build(s);
        vector<pair<int, int>>intervals;
        for(int i = 0;i<manCharArr.size();i++){
            int palindromLen = manCharArr[i]-1;
            if(palindromLen >= k){
                for(int j = palindromLen;j>=k;j-=2){
                // get the starting and ending point 
                int cen = i;
                int start = (cen - j)/2;
                int end = start + j-1;
                    intervals.push_back({start, end});
                }
            }
        }
        // sort the intervals 
        // get the count of non-overlapping intervals 
        sort(intervals.begin(), intervals.end(), comp);
        cout<<intervals.size()<<endl;
        // find non-overlapping
        int count = 0;
        int last_picked_end = -1;
        for(int i = 0;i<intervals.size();i++){
            if(intervals[i].first > last_picked_end){
                count++;
                last_picked_end = intervals[i].second;
            }
        }
        return count;
    }
};