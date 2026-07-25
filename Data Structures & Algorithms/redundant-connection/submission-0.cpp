class Solution {
public:

    void makeUnion(int x, int y, vector<int> &parent, vector<int> &rank){
        int xParent = find(x, parent); 
        int yParent = find(y, parent); 

        if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent; 
        }else if(rank[yParent] > rank[xParent]){
            parent[xParent] = yParent; 
        }else{
            parent[xParent] = yParent; 
            rank[yParent]++; 
        }
    }

    int find(int i, vector<int> &parent){
        if(i == parent[i]){
            return i; 
        }
        return parent[i] = find(parent[i], parent); 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<int> parent(n+1); 

        //each vertex is its own parent
        for(int i = 0; i < n; i++){
            parent[i] = i; 
        }
        vector<int> rank(n+1, 0); 

        for(auto &x:edges){
            int a = x[0]; 
            int b = x[1]; 

            if(find(a, parent) == find(b, parent)){
                return {a,b}; 
            }else{
                makeUnion(a, b, parent, rank); 
            }
        }

        return {}; 
    }
};
