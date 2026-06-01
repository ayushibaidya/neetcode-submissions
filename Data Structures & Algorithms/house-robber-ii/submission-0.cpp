class Solution {
public:

    int helper(vector<int>&house){
        int rob1 = 0, rob2 = 0; 

        for(int num:house){
            int newRob = max(rob1 + num, rob2);
            rob1 = rob2; 
            rob2 = newRob;
        }
        return rob2; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return nums[0]; 

        vector<int> houseFirst(nums.begin()+1, nums.end()); 
        vector<int> houseLast(nums.begin(), nums.end()-1); 

        return max(nums[0], max(helper(houseFirst), helper(houseLast))); 
    }
};
