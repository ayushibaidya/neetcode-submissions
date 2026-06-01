class Solution {
public:

    void backTrack(vector<int> &nums, vector<int> &subset, vector<vector<int>>&results, int n){
        //base case
        results.push_back(subset); 
        
        for(int i = n; i < nums.size(); i++){
            subset.push_back(nums[i]); 
            backTrack(nums, subset, results, i+1); 
            subset.pop_back(); 
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        //subset will be one answer that will push_back into results
        vector<int> subset; 
        vector<vector<int>> results; 

        backTrack(nums, subset, results, 0); 
        return results; 
    }
};
