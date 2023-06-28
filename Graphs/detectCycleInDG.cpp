//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


bool dfs(int i,int &v,vector<int> adj[],vector <int> &vis){
    vis[i] = 1;
    for(auto it:adj[i])
        if(vis[it] == 1 || (!vis[it] && dfs(it,v,adj,vis))) return 1;
    vis[i] = 2;
    return 0;
}
bool isCyclic(int v, vector<int> adj[]) {
    vector <int> vis(v);
    for(int i = 0;i < v;i++){
        if(!vis[i])
            if(dfs(i,v,adj,vis)) return 1;
    }
    return 0;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
