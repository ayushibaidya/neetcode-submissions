class Solution {
public:

    int dfs(int i, int sum, vector<int> &nums, int target, int totalSum, vector<vector<int>> &dp){
        if(i == nums.size()) return sum == target ? 1 : 0; 

        int index = sum + totalSum; 

        if(dp[i][index] != -1){
            return dp[i][index]; 
        }

        int add = dfs(i+1, sum + nums[i], nums, target, totalSum, dp); 
        int subtract = dfs(i+1, sum-nums[i], nums, target, totalSum, dp); 
        return dp[i][index] = add + subtract; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(); 

        int totalSum = 0; 

        for(int num:nums){
            totalSum += num; 
        }

        vector<vector<int>> dp(n, vector<int>(2*totalSum+1, -1)); 

        return dfs(0, 0, nums, target, totalSum, dp); 
    }
};
