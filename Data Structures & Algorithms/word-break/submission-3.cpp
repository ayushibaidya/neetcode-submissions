class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); 
        vector<bool> dp(n+1, false); 

        dp[0] = 1; 

        for(int i = 0; i < n; i++){
            if(!dp[i]) continue; 

            for(string word:wordDict){
                int len = word.size(); 
                if(i + len <= s.size() && s.substr(i, len) == word){
                    dp[i+len] = true; 
                }
            }
        }
        return dp[n]; 
    }
};
