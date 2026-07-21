class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for (auto &f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        // node, {cost, stops}

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({src, {0, -1}});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int node = curr.first;
            int cost = curr.second.first;
            int stops = curr.second.second;

            for (auto neighbor : graph[node]) {
                int v = neighbor.first;
                int wt = neighbor.second;

                if (stops + 1 <= k &&
                    cost + wt < dist[v]) {

                    dist[v] = cost + wt;
                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};