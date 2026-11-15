#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Standard DSU implementation
    struct DSU {
        vector<int> par, rank;
        
        DSU(int n) {
            par.resize(n);
            rank.resize(n, 1);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }
        
        int findRoot(int node) {
            if (par[node] == node) return node;
            return par[node] = findRoot(par[node]); // Path compression
        }
        
        void merge(int u, int v) {
            int rootU = findRoot(u);
            int rootV = findRoot(v);
            if (rootU == rootV) return;
            
            // Union by rank
            if (rank[rootU] >= rank[rootV]) {
                rank[rootU] += rank[rootV];
                par[rootV] = rootU;
            } else {
                rank[rootV] += rank[rootU];
                par[rootU] = rootV;
            }
        }
    };

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        int numEdges = edgeList.size();
        
        // 1. Prepare queries for offline processing
        // We append the original index to each query so we know where to store the answer after sorting
        vector<vector<int>> sortedQueries;
        for (int i = 0; i < numQueries; i++) {
            sortedQueries.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }
        
        // 2. Sort queries by their limit in ascending order
        sort(sortedQueries.begin(), sortedQueries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        // 3. Sort edges by their weight in ascending order
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        DSU dsu(n);
        vector<bool> ans(numQueries);
        int edgeIndex = 0;
        
        // 4. Process each query using the two-pointer approach
        for (int i = 0; i < numQueries; i++) {
            int u = sortedQueries[i][0];
            int v = sortedQueries[i][1];
            int limit = sortedQueries[i][2];
            int originalIndex = sortedQueries[i][3];
            
            // Batch Add: Add all edges strictly less than the current query's limit
            // Notice how edgeIndex only moves forward and never resets!
            while (edgeIndex < numEdges && edgeList[edgeIndex][2] < limit) {
                dsu.merge(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
                edgeIndex++;
            }
            
            // Answer the query: Are u and v in the same component now?
            ans[originalIndex] = (dsu.findRoot(u) == dsu.findRoot(v));
        }
        
        return ans;
    }
};