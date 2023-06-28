//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfscheck(int node, int V, vector<int> adj[], int vis[], int pathvis[],
    int check[]){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfscheck(node, V, adj, vis, pathvis, check) == true){
                    check[node] = 0;
                    return true;
                }
            }else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        int check[V] = {0};
        vector<int> safenodes;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfscheck(i, V, adj, vis, pathvis, check);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};


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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
