class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 

        unordered_map<int, int> count; 

        for(auto& num:nums){
            count[num]++; 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 


        for(auto& c:count){
            pq.push({c.second, c.first}); 
            if(pq.size() > k){
                pq.pop(); 
            }
        }

        vector<int> ans; 
        while(!pq.empty()){
            ans.push_back(pq.top().second); 
            pq.pop(); 
        }
        return ans; 
    }
};
