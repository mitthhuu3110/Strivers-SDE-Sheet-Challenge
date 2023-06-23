//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> list[], int vis[]){
        vis[node] = 1;
        for(auto it: list[node]){
            if(!vis[it]) {
                dfs(it, list, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> list[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        
        
        int vis[V] = {0};
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;
                dfs(i, list, vis);
            }
        }
        
        return count;
    }
};
