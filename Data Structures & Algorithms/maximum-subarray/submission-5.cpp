class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 

        int maxCurr = nums[0]; 
        int maxSum = nums[0];  

        for(int i = 1; i < n; i++){
            maxCurr = max(nums[i], nums[i]+maxCurr); 
            maxSum = max(maxSum, maxCurr); 
        }
        return maxSum; 
    }
};
