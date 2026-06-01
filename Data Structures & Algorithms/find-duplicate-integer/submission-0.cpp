class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set; 
        for(auto n:nums){
            if(set.count(n)){
                return n; 
            }
            set.insert(n);
        }
        return -1; 
    }
};
