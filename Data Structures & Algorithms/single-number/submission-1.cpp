class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        0011
        0010
        0001
        0011
        0010
        */

        int n = nums.size(); 
        int ans = nums[0];  
        for(int i = 1; i < n; i++){
            ans = ans^nums[i]; 
        }
        return ans;
    }
};
