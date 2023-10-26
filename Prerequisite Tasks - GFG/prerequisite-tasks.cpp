//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     int topoSort(int V, vector<int>adj[]){
        stack<int>st;
    
        queue<int>q;
        vector<int>indegree(V,0);
        for(int i= 0;i<V;i++){
            int u = i;
            for(auto x: adj[i]){
                int v = x;
                indegree[v]++;
            }
        }
        for(int i = 0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        int count = 0;
        while(q.size()!=0){
            int node = q.front();
            q.pop();
            count+=1;
            for(auto adjnode: adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode]==0)q.push(adjnode);
            }
        }
      return count;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    for(int i = 0;i<P;i++){
	        int u = prerequisites[i].second;
	        int v = prerequisites[i].first;
	        adj[u].push_back(v);
	    }
	    int count = topoSort(N, adj);
	    if(count==N)return true;
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends