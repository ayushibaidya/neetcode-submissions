class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj; 

        //build graph 
        //create node out of each letter in all the given words
        for(string &word: words){
            for(char c:word){
                adj[c]; 
            }
        }

        //build edges
        for(int i = 0; i < words.size()-1; i++){
    string &w1 = words[i];
    string &w2 = words[i+1];

    int j = 0;
    while(j < w1.size() && j < w2.size() && w1[j] == w2[j]){
        j++;
    }

    if(j < w1.size() && j < w2.size()){
        adj[w1[j]].insert(w2[j]);
    }
    else if(w1.size() > w2.size()){
        return "";
    }
}
        //compute indegree
        unordered_map<char, int> indegree; 
        for(auto &[c,_]:adj){
            indegree[c] = 0; 
        }

        for(auto &[u, neighbors]:adj){
            for(char v:neighbors){
                indegree[v]++; 
            }
        }
        
        string result; 

        queue<char> q; 
        for(auto &[c, deg]:indegree){
            if(deg == 0) q.push(c); 
        }

        while(!q.empty()){
            char curr = q.front(); 
            q.pop(); 

            result += curr; 

            for(char next:adj[curr]){
                indegree[next]--; 
                if(indegree[next] == 0){
                    q.push(next); 
                }
            }
        }

        if(result.size() != adj.size()){
            return ""; 
        }
        return result; 
    }
};
