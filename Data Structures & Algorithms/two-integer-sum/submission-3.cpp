class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        vector<int> ans; 
        unordered_map<int, int> mp; 

        for(int i = 0; i < n; i++){
            int diff = target-nums[i]; 
            if(mp.find(diff) != mp.end()){
                ans.push_back(i); 
                ans.push_back(mp[diff]); 
            }
            mp.insert({nums[i], i}); 
        }
        sort(ans.begin(), ans.end()); 
        return ans; 
    }
};
