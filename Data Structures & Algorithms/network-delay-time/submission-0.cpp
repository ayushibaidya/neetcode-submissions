class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //k - source node 
        //n - no of nodes 
        //times - u->v, wt 

        vector<vector<pair<int, int>>> adj(n+1); 

        //u -> {v,wt}
        for(auto& t:times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        // priority_queue<int> pq; 
        // priority_queue<int, vector<int>, greater<int>> pq; 
        // priority_queue<pair<int, int>> pq; 

        //min heap pair 
        priority_queue<pair<int, int>,
         vector<pair<int, int>>, 
         greater<pair<int, int>>> pq; 

        //store the distances initialized by infinity 
        vector<int> dist(n+1, INT_MAX); 
        //dist of source is 0 
        dist[k] = 0; 

        //dist, node 
        pq.push({0, k}); 

        while(!pq.empty()){
            auto [time, node] = pq.top(); 
            pq.pop(); 

            for(auto &neighbor:adj[node]){
                int nextNode = neighbor.first; 
                int weight = neighbor.second; 

                if(dist[nextNode] > time+weight){
                    dist[nextNode] = time+weight; 
                    pq.push({dist[nextNode], nextNode}); 
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
