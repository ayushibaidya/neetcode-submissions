class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1; 

        for(int neighbor:adj[node]){
            if(vis[neighbor] == 0){
                if(dfs(neighbor, adj, vis)){
                    return true; 
                }
            }else if(vis[neighbor] == 1){
                return true; //present in current recursion stack
            }
        }
            vis[node] = 2; //fully processed
            return false; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses, 0); 
        vector<vector<int>> adj(numCourses); 

        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]); 
        }

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis)){
                    return false; 
                } 
            }
        }
        return true; 
    }
};
