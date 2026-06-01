class Solution {
public:

    void backTrack(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &results, int index){
        if(target == 0){
            results.push_back(temp); 
            return; 
        }
        
        if(target < 0 || index >= candidates.size()){
            return; 
        }

        //include candidates
        temp.push_back(candidates[index]);  
        backTrack(candidates, target-candidates[index], temp, results, index+1); 
        temp.pop_back(); 

        while(index+1 < candidates.size() && candidates[index] == candidates[index+1]){
            index++; 
        }

        //exlude candidates
        backTrack(candidates, target, temp, results, index+1); 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results; 
        vector<int> temp; 
        sort(candidates.begin(), candidates.end()); 
        backTrack(candidates, target, temp, results, 0); 
        return results; 
    }
};
