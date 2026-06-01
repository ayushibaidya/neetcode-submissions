class Solution {
public:

    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        vis[node] = 1; 

        for(auto c:adj[node]){
            if(vis[c] == 0){
                dfs(adj, vis, c); 
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]); 
        }
        
        vector<int> vis(n, 0); 
        int components = 0; 

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                components++; 
                dfs(adj, vis, i); 
            }
        }
        return components; 
    }
};
