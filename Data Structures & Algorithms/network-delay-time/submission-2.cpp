class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //step 1 
        //build the graph using the given edge list
        //adj - node - {edgeVal, weight}
       
        vector<vector<pair<int, int>>> adj(n+1); //n+1 because nodes range starts from 1 not 0 

        for(auto& t:times){
            adj[t[0]].push_back({t[1], t[2]}); 
        }

        //step 2
        //build a dist array - initialize with INT_MAX
        vector<int> dist(n+1, INT_MAX); 

        //k is the source node 
        dist[k] = 0; 

        //min heap pq 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; 

        //push the starting node - {dist, node}
        pq.push({0, k}); 
        //now we start processing the nodes
        while(!pq.empty()){
            auto [d, node] = pq.top(); 
            pq.pop(); 

            if(d > dist[node]) continue; 

            for(auto& [neighbour, wt]:adj[node]){
                if(d + wt < dist[neighbour]){
                    dist[neighbour] = d+wt; 
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        int maxTime = 0; 
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1; 
            }
            maxTime = max(maxTime, dist[i]); 
        }
        return maxTime; 
    }
};
