class Solution {
public:

    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        if(vis[node] == 1) return false; 
        if(vis[node] == 2) return true; 
        
        vis[node] = 1; 

        for(auto c:adj[node]){
            if(!dfs(adj, vis, c)) return false; 
        }

        vis[node] = 2; 
        return true; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]); 
        }

        vector<int> vis(numCourses, 0); 

        for(int i = 0; i < numCourses; i++){
                if(vis[i] == 0){
                    if(!dfs(adj, vis, i)) return false;
                } 
        }
        return true; 
    }
};
