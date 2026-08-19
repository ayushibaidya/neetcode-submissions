class Solution {
public:

    void dfs(map<string, multiset<string>>& adj,
             vector<string>& res,
             string src) {

        while(!adj[src].empty()) {

            string dest = *adj[src].begin();

            adj[src].erase(adj[src].begin());

            dfs(adj, res, dest);
        }

        res.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        map<string, multiset<string>> adj;

        for(auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        vector<string> res;

        dfs(adj, res, "JFK");

        reverse(res.begin(), res.end());

        return res;
    }
};