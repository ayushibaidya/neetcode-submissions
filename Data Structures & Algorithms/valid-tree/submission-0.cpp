class Solution {
public:

    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int src, int parent){
        if(vis[src]) return false; 

        vis[src] = true; 

        for(int neighbor:adj[src]){

            if(neighbor == parent){
                continue; 
            }

            if(vis[neighbor]){
                return false; 
            }
            if(!(dfs(adj, vis, neighbor, src))){
                return false; 
            }
        }
        return true; 
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false); 
        vector<vector<int>> adj(n); 

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]); 
        }

        if(!dfs(adj, vis, 0, -1)){
            return false; 
        }

        for(bool v : vis) {
            if(!v)
                return false;
        }
        return true; 
    }
};
