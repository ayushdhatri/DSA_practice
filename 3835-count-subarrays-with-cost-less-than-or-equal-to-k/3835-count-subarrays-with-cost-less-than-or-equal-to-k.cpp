class Solution {
public:
bool check(multiset<long long>&st, int ele, int tail, int head, long long k){
    if(st.size() == 0)return true;
    long long min_ele = min<long long>(*st.begin(), ele);
    long long max_ele = max<long long >(*st.rbegin(), ele);
    return ((max_ele - min_ele)*(head-tail+2)) <= k;
}
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int tail = 0, head = -1;
        long long count = 0;
        // ds to process the answer
        multiset<long long>st;

        while(tail < n){
            // eat as much as you can 
            while(head + 1 < n && (check(st, nums[head+1], tail, head, k))){
                head+=1;
                st.insert(nums[head]);
            }
            // update the answer
            count+=(head-tail+1);
            if(tail > head){
                tail +=1;
                head = tail - 1;
            }
            else{
                auto it = st.find(nums[tail]);
                if (it != st.end()) {
                    st.erase(it);
                }
                tail+=1;
            }
        }
        return count;
        
    }
};