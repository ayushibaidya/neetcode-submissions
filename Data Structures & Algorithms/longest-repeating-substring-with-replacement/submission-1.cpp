class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int length = 0; 
        int longestSubstring = 0; 

        int i = 0;

        vector<int>count(26, 0); 

        int maxFreq = 0;  

        for(int j = 0; j < n; j++){
            count[s[j]-'A']++; 
            maxFreq = max(maxFreq, count[s[j]-'A']); 
            while((j-i+1) - maxFreq > k){
                count[s[i]-'A']--; 
                i++; 
            }
            longestSubstring = max(longestSubstring, j-i+1); 
        }
        return longestSubstring; 
    }
};
