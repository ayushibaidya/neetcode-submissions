class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); 

        int currSum = 0; 
        int length = INT_MAX; 

        int j = 0; 

        for(int i = 0; i < n; i++){
          currSum += nums[i]; 
          while(currSum >= target){
            length = min(length, i-j+1); 
            currSum -= nums[j]; 
            j++; 
          }
        }
        if(length == INT_MAX) return 0; 
        return length; 
    }
};