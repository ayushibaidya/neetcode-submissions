class Solution {
public:

    void backTrack(vector<int> &nums, vector<int> &subset, vector<vector<int>>&results, int i){
        //base case
        if(i == nums.size()){
            results.push_back({subset}); 
            return; 
        }
        subset.push_back(nums[i]); 
        //include 
        backTrack(nums, subset, results, i+1); 
        subset.pop_back(); 

        //exclude
        backTrack(nums, subset, results, i+1); 
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        //subset will be one answer that will push_back into results
        vector<int> subset; //temp
        vector<vector<int>> results; //output

        backTrack(nums, subset, results, 0); 
        return results; 
    }
};
