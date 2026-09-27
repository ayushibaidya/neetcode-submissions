class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> ans(nums.begin(), nums.end()); 

        int i = 0; 
        while(i < n){
            ans.push_back(nums[i]); 
            i++; 
        }

        return ans; 
    }
};