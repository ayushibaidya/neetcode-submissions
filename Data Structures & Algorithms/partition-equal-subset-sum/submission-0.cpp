class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 

        int totalSum = 0; 

        for(int i = 0; i < n; i++){
            totalSum += nums[i]; 
        }

        if(totalSum % 2 != 0) return false; 

        int target = totalSum/2; 

        vector<bool> dp(target+1, 0); 
        dp[0] = 1; 

        for(int i = 0; i < n; i++){
            //some logic of totalSum - nums[i] 
            int num = nums[i]; 
            for(int j = target; j >= num; j--){
                if(dp[j-num]){
                    dp[j] = true; 
                }
            }
        }
        return dp[target]; 
    }
};
