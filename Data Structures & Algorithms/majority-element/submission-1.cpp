class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); 

        unordered_map<int, int> count; 

        for(auto& c:nums){
            count[c]++; 
        }

        for(auto& p:count){
            if(p.second > n/2){
                return p.first; 
            }
        }
        return -1; 
    }
};