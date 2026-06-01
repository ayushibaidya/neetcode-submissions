class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); 

        unordered_set<int> store(nums.begin(), nums.end()); 

        int maxLength = 0; 

        for(int s:store){
            int curr = s;
            int length = 1; 
                while(store.find(curr+1) != store.end()){
                    length++; 
                    curr++; 
                }
            maxLength = max(maxLength, length); 
        }
        return maxLength; 
    }
};
