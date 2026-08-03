class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st; 

        for(auto &n:nums){
            if(st.find(n) != st.end()){
                return true; 
            }
            st.insert(n); 
        }
        return false; 
    }
};