class Solution {
public:

    void backTrack(vector<int> &nums, vector<vector<int>> &results, int index){
        if(index == nums.size()){
            results.push_back({nums}); 
            return; 
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]); 
            backTrack(nums, results, index+1); 
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp; 
        vector<vector<int>> results; 

        backTrack(nums, results, 0); 
        return results; 
    }
};
