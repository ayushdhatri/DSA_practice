struct DSU{
    int n, *parent, *rank;
    DSU(int x){
        n = x;
        parent = new int[n];
        rank = new int[n];
        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        int xroot = find(x), yroot = find(y);
        if(xroot == yroot){
            // there is not point of merging
        }
        else{
            if(rank[xroot] < rank[yroot]){
                rank[yroot] += rank[xroot];
                parent[xroot] = parent[yroot];
            }
            else{
                rank[xroot] += rank[yroot];
                parent[yroot] = parent[xroot];
            }

        }
    }


};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // we will merge smaller set to larger set
        int n = accounts.size();
        DSU dsu(n);
        set<string> emailList[n];
        map<string, int>emailMap;
        int  mark_merge = -1;
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(emailMap.find(accounts[i][j]) == emailMap.end()){
                    emailMap[accounts[i][j]] = i;
                }
                else{
                     dsu.merge(i,emailMap[accounts[i][j]]);
                }
            }
        }
        for(int i = 0;i<n;i++){
            int root = dsu.find(i);
            for(int j = 1;j<accounts[i].size();j++){
                emailList[root].insert(accounts[i][j]);
            }
        }
        vector<vector<string>>ans;
        for(int i = 0;i<n;i++){
            vector<string>temp;
            if(emailList[i].size()!=0){
                // it has few email just check who is the owner, and all the emailList of this setup
                string name = accounts[i][0];
                temp.push_back(name);
                for(auto x : emailList[i]){
                    temp.push_back(x);
                }   
                ans.push_back(temp);

            }
        }

        return ans;

        
    }
};