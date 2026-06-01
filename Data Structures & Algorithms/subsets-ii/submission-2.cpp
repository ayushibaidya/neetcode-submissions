class Solution {
public:

    void backTrack(vector<int> &nums, int pos, vector<int> &subsets, vector<vector<int>> &allSubsets){
        allSubsets.push_back(subsets); 
        
        for(int i = pos; i < nums.size(); i++){
            if(i > pos && nums[i] == nums[i-1]) continue; 
            subsets.push_back(nums[i]); 
            backTrack(nums, i+1, subsets, allSubsets); 
            subsets.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets; 
        vector<int> subset; 

        sort(nums.begin(), nums.end()); 

        backTrack(nums, 0, subset, allSubsets); 

        return allSubsets; 
    }
};
