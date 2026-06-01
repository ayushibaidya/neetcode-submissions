class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j = 0; 
        unordered_set<char> set; 
        int len = 0; 

        if(s.size() == 1){
            return 1; 
        }

        while(j < s.size()){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j]); 
                j++; 
                len = max(len, j-i); 
            }else{
                set.erase(s[i]);
                i++;
            }
        }
        return len; 
    }
};
