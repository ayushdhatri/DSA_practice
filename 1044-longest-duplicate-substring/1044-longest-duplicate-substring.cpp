class Solution {
public:
    struct hasher{
        int n, _k, _p;
        vector<int> base;
        vector<int> powk;

        void init(string &s, int k, int p){
            this->n = s.size(); this->_k = k; this->_p = p;
            base.resize(n+1);
            powk.resize(n+1);

            base[0] = 0;
            powk[0] = 1;

            for(int i = 0;i<n;i++){
                int num = s[i] - 'a' + 1;
                base[i+1] = (num + 1LL*base[i]*k)%p;
                powk[i+1] = (1LL*powk[i] * k)%p;
            }
        }

        int getHash(int l, int r){
            // if l and r are zero based convert them to 1 
            l++;r++;
            int ans = base[r] - (1LL*base[l-1]*powk[r-l+1])%_p;
            return (ans + _p)%_p;
        }

    };

    struct double_hash{
        hasher a, b;
        void init(string &s){
            a.init(s, 31, 1000000007);
            b.init(s, 37, 1000000021);
        }

        pair<int, int> getHash(int l, int r){
            return {
                a.getHash(l, r),
                b.getHash(l, r)
            };
        }
    };

    bool check(int len, string &s, double_hash &a){
        set<pair<int, int>>st;
        int n = s.size();
        for(int start = 0;start+len-1<n;start++)
        {
            int end = start + len -1;
            if(st.find(a.getHash(start, end)) != st.end()){
                return true;
            }
            st.insert(a.getHash(start, end));
        }
        return false;
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        double_hash a;
        a.init(s);
        int ans = 0;
        int low = 0 ;
        int high = n;
        int start_index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, s,a)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        if(ans == 0){
            return "";
        }
       
        // traverse that lenght and get the answer
        set<pair<int, int>>st;
        for(int start = 0;start+ans-1<n;start++)
        {
            int end = start + ans -1;
            if(st.find(a.getHash(start, end)) != st.end()){
                return s.substr(start, ans);
            }
            st.insert(a.getHash(start, end));
        }
        return "";


        
        
    }
};