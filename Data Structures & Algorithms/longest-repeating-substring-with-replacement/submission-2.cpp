class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 

        unordered_map<char, int> freq; 
        int j = 0;
        int maxLen = 0; 
        int maxFreqC = 0; 
        for(int i = 0; i < n; i++){
            freq[s[i]]++;
            maxFreqC = max(maxFreqC, freq[s[i]]);
            while(i-j+1 - maxFreqC > k){
                freq[s[j]]--; 
                j++; 
            } 
            maxLen = max(maxLen, i-j+1); 
        }
        return maxLen; 
    }
};
