class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(); 
        int minSum = INT_MAX; 
        int maxSum = INT_MIN; 
        int currMin = 0; 
        int currMax = 0; 

        int totalSum = 0; 

        for(int i = 0; i < n; i++){
            totalSum += nums[i]; 
        }

        for(int i = 0; i < n; i++){
            currMin = min(nums[i], currMin + nums[i]); 
            minSum = min(minSum, currMin); 
            currMax = max(nums[i], currMax + nums[i]); 
            maxSum = max(maxSum, currMax); 
        }
        if(totalSum - minSum == 0){
            return maxSum; 
        }
        return max(maxSum, totalSum - minSum); 
    }
};