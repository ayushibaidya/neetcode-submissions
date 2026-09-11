class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); 

        unordered_set<int> stored; 

        for(int num:nums){
            stored.insert(num); 
        }

        int maxCount = 0; 

        for(int num:nums){
            if(stored.find(num-1) == stored.end()){
                int curr = num; 

                int count = 1; 

                while(stored.find(curr+1) != stored.end()){
                    curr++; 
                    count++; 
                }
                maxCount = max(maxCount, count); 
            }
        }
        
        return maxCount; 
    }
};
