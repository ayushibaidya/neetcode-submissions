class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 

        for(auto &num:nums){
            freq[num]++; 
        }

        //min heap 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

        for(auto &it:freq){
            pq.push({it.second, it.first}); 
            if(pq.size() > k){
                pq.pop(); 
            }
        }

        vector<int> ans; 

        while(!pq.empty()){
            int element = pq.top().second; 
            pq.pop(); 
            ans.push_back(element); 
        }
        return ans; 
    }
};
