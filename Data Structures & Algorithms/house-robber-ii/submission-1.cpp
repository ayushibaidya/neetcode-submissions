class Solution {
public:

    int houseRob(vector<int> nums, int start, int end){
        int len = end-start+1; 
        vector<int>dp(len); 

        dp[0] = nums[start]; 
        dp[1] = max(nums[start], nums[start+1]); 

        for(int i = 2; i < len; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[start+i]); 
        }
        return dp[len-1]; 
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 

        if(n == 1) return nums[0]; 

        int rob1 = houseRob(nums, 0, n-2); 
        int rob2 = houseRob(nums, 1, n-1); 

        return max(rob1, rob2); 
    }
};
