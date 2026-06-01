class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(); 

        vector<int> ans; 

        for(int i = 0; i < size; i++){
            int product = 1; 
            for(int j = 0; j < size; j++){
                if(i != j){
                    product *= nums[j]; 
                }
            }
            ans.push_back(product); 
        }
        return ans; 
    }
};
