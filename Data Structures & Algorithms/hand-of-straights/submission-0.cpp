class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false; 

        unordered_map<int, int> mp; 
        priority_queue<int, vector<int>, greater<int>> pq; 

        for(auto c:hand){
            mp[c]++; 
            pq.push(c); 
        } 

        while(!pq.empty()){
            while(!pq.empty() && mp[pq.top()] == 0){
                pq.pop(); 
            }
            if(pq.empty()) break; 

            int start = pq.top();
            for(int i = start; i < start + groupSize; i++){
                if(mp[i] == 0){
                    return false; 
                }
            mp[i]--; 
            }
        }
        return true; 
    }
};
