class Solution {
public:

    // int dfs(vector<int>&nums, int i){
    //     if(i >= nums.size()) return 0; 

    //     return max(dfs(nums, i+1), nums[i]+dfs(nums, i+2)); 
    // }

    // int rob(vector<int>& nums) {
    //     return dfs(nums, 0); 
    // }

    // int rob(vector<int>&nums){

    //     if(nums.empty()) return 0; 
    //     if(nums.size() == 1) return nums[0]; 

    //     int n = nums.size(); 
    //     vector<int> dp(n); 

    //     dp[0] = nums[0]; 
    //     dp[1] = max(nums[1], nums[0]); 
        
    //     for(int i = 2; i < n; i++){
    //         dp[i] = max(dp[i-1], nums[i]+dp[i-2]); 
    //     }
    //     return dp[n-1]; 
    // }

    int dfs(vector<int> &nums, vector<int> &memo, int pos){
        if(pos >= nums.size()) return 0; 
        //if value has been computer return value 
        if(memo[pos] != -1){
            return memo[pos]; 
        }

        memo[pos] = max(dfs(nums, memo, pos+1), nums[pos] + dfs(nums, memo, pos+2)); 
        return memo[pos]; 
    }

    int rob(vector<int>&nums){
        int n = nums.size(); 
        vector<int> memo(n, -1); 
        return dfs(nums, memo, 0); 
    }
};
