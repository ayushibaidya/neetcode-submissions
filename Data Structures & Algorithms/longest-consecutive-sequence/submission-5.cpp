class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); 

        int count = 0; 

        for(auto &n:st){
            if(st.find(n-1) == st.end()){
                int length = 1; 
                while(st.find(n+length) != st.end()){
                    length++; 
                }
                count = max(count, length); 
            }
        }

        return count; 
    }
};
