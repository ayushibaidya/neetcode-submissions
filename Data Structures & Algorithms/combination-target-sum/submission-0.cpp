class Solution {
public:

    void getAllCombinations(vector<int> &nums, int target, vector<int> &combination, vector<vector<int>> &uniqueCombinations, int i, int sum){

        if(sum == target){
            uniqueCombinations.push_back(combination); 
            return; 
        }

        if(sum > target || i == nums.size()) return; 
        
        combination.push_back(nums[i]); 
        //inlcude
        getAllCombinations(nums, target, combination, uniqueCombinations, i, sum+nums[i]); 
        combination.pop_back(); 
        //exclude
        getAllCombinations(nums, target, combination, uniqueCombinations, i+1, sum); 
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> uniqueCombinations; 
        //temp array of one valid (target == 9) combination  
        vector<int> combination; 
        
        getAllCombinations(nums, target, combination, uniqueCombinations, 0, 0);
        //return a list of unique combinations
        return uniqueCombinations; 
    }
};
