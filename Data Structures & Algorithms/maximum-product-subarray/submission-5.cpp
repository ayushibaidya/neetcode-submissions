class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> prefix(n); 
        prefix[0] = nums[0]; 

        for(int i = 1; i < n; i++){
            if(prefix[i-1] == 0){
                prefix[i] = nums[i]; 
            } 
            else{
                prefix[i] = prefix[i-1]*nums[i];
            } 
        }

        vector<int> suffix(n); 
        suffix[n-1] = nums[n-1]; 

        for(int i = n-2; i >= 0; i--){
            if(suffix[i+1] == 0){
                suffix[i] = nums[i]; 
            }
            else{
                suffix[i] = suffix[i+1]*nums[i]; 
            }
        }

        int maxProduct = INT_MIN; 
        for(int i = 0; i < n; i++){
            maxProduct = max(maxProduct, max(prefix[i],suffix[i])); 
        }

        return maxProduct; 

        //1 2 -6 -24
        //-24 -24 -12 4
        //
    }
};
