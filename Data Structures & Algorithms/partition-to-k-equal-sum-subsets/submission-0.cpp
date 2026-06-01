class Solution {
public:

    bool backTrack(vector<int> &nums, int k, int target, int start, int currSum, vector<bool> &used){
        if(k == 1) return true; 
        
        if(currSum == target){
            return backTrack(nums, k-1, target, 0, 0, used);  
        }

        for(int i = start; i < nums.size(); i++){
            if(used[i]) continue; 

            if(currSum + nums[i] > target) continue; 

            used[i] = true; 

           if (backTrack(nums, k, target, i + 1, currSum + nums[i], used)){
                return true; 
            }
            used[i] = false; 
        }
        return false; 
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(); 

        int totalSum = 0; 
        for(int i = 0; i < n; i++){
            totalSum += nums[i]; 
        }

        if (totalSum % k != 0) return false;

        sort(nums.begin(), nums.end()); 
        if(nums[n-1] > totalSum/k) return false; 
        vector<bool> used(n, false); 

        return backTrack(nums, k, totalSum/k, 0, 0, used); 
    }
};