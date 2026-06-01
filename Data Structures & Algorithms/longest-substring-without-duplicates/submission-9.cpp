class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; 

        int length = 0; int j = 0; 

        for(int i = 0; i < s.size(); i++){ 
            while(st.find(s[i]) != st.end()){
                st.erase(s[j]); 
                j++; 
            }
            st.insert(s[i]); 
            length = max(length, i-j+1);   
        }
        return length; 
    }
};
