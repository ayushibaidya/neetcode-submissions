class Solution {
public:

    void backTrack(vector<int> &candidates, int pos, vector<int>&combination, vector<vector<int>> &results, int target){
        if(target == 0){
            results.push_back(combination); 
            return; 
        }

        for(int i = pos; i < candidates.size(); i++){
            if(i > pos && candidates[i] == candidates[i-1]){
                continue; 
            }
            if(candidates[i] <= target){
                combination.push_back(candidates[i]); 
                backTrack(candidates, i+1, combination, results, target-candidates[i]); 
                combination.pop_back(); 
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>combination; 
        vector<vector<int>> results; 
        sort(candidates.begin(), candidates.end()); 
        backTrack(candidates, 0, combination, results, target); 
        return results; 
    }
};
