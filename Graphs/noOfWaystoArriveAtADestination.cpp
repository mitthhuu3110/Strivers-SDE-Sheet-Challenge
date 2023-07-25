//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int, int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>> >pq;
        
        int mod=(1e9+7);
        vector<long>dist(n, 1e18); 
        vector<int>ways(n, 0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            long d=it.first;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                long edD=it.second;
                
                if(edD+d<dist[adjNode]){
                    dist[adjNode]=edD+d;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode]=ways[node]%mod;
                }
                else if(edD+d==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
