class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int numsTotal = 0;  
        
        for(int i = 0; i < nums.size(); i++){
            numsTotal += nums[i]; 
        }

        int total = 0; 
        for(int i = 0; i <= nums.size(); i++){
            total += i; 
        }

        return total-numsTotal; 
    }
};
