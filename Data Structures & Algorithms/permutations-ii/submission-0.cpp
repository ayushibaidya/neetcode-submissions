class Solution {
public:

    void backTrack(vector<int> &nums, vector<int> &temp, vector<bool> &used, vector<vector<int>> &results){
        if(temp.size() == nums.size()){
            results.push_back(temp); 
            return; 
        }

// skip duplicates 
//if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue; 
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue; 
            temp.push_back(nums[i]); 
            used[i] = true; 
            backTrack(nums, temp, used, results); 
            temp.pop_back(); 
            used[i] = false; 
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); 

        vector<int> temp; 
        vector<bool> used(n, false); 
        vector<vector<int>> results; 
        backTrack(nums, temp, used, results); 

        return results; 
    }
};