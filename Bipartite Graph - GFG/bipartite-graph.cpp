//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int source,int V, vector<int>adj[],vector<bool>&visited, vector<int>&color){
        
	    
	    queue<pair<pair<int, int>,int>>q;
	    q.push({{source,-1},0});
	    color[source]=0;
	    visited[source]=true;
	    while(q.size()!=0){
	        int node = q.front().first.first;
	        int par = q.front().first.second;
	        int node_clr = q.front().second;
	        q.pop();
	        for(auto x: adj[node]){
	             if(visited[x]==true){
	                 if(x!=par&&color[x]==color[node])return false;
	                    
	             }
	             else
	             {
	                 visited[x]=true;
	                 color[x]=!node_clr;
	                 q.push({{x, node},color[x]});
	                 
	             }
	        }
	    }
	    return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool>visited(V,false);
	    vector<int>color(V, -1);
	    for(int i =0;i<V;i++){
	        if(visited[i]==false)
	        {
	            bool temp = check(i, V, adj,visited,color);
	            if(temp==false)return false;
	        }
	    }
	    return true;
	    
	   
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends