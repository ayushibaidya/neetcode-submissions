class Solution {
public:

    int func(vector<int> &nums, int n){
        if(n == 0) return 0; 
        if(n == 1) return nums[0]; 

        vector<int> dp(nums.size(), 0); 

        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]); 

        for(int i = 2; i < n; i++){
            int take = nums[i] + dp[i-2]; 
            int notTake = dp[i-1]; 

            dp[i] = max(take, notTake); 
        }
        return dp[n-1]; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); 
        
        if(n == 1) return nums[0]; 

        vector<int> part1(nums.begin(), nums.end()-1); 
        vector<int> part2(nums.begin()+1, nums.end()); 

        int val1 = func(part1, part1.size()); 
        int val2 = func(part2, part2.size()); 

        return max(val1, val2); 
    }
};
