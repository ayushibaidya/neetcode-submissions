class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> letterCount; 

        //store the count of the letters 
        //26 is constant 
        for(auto it:tasks){
            letterCount[it]++; 
        }
        
        priority_queue<pair<int, char>> pq; 

        for(auto it:letterCount){
            pq.push({it.second, it.first}); 
        }

        int time = 0; 
        queue<pair<pair<int, char>, int>> q; 

        while(!pq.empty() || !q.empty()){
            time++; 
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                auto curr = pq.top(); 
                pq.pop(); 
                curr.first--; 
                if(curr.first > 0){
                    q.push({curr, time + n + 1}); 
                }
            }
        }

        return time; 
    }
};
