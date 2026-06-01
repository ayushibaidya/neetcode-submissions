class Solution {
public:
    bool dfsTopo(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
        vis[node] = 1; 

        for(int neighbour:adj[node]){
            if(vis[neighbour] == 0){
                if(dfsTopo(neighbour, adj, vis, ans)){
                    return true; 
                } 
            }else if(vis[neighbour] == 1){
                return true; 
            }
        }
        vis[node] = 2; 
        ans.push_back(node); 
        return false; 
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0); 

        vector<vector<int>> adj(numCourses); 
        vector<int>ans; 

        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]); 
        }

        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(dfsTopo(i, adj, vis, ans)){
                    return {}; 
                } 
            }
        }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};
