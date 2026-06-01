class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(); 
        vector<bool> dp(n, 0); 
        dp[0] = 1; 

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                for(int j = i-maxJump; j <= i-minJump; j++){
                    if(j >= 0 && dp[j]){
                        dp[i] = true; 
                        break; 
                    }
                }
            }
        }
        return dp[n-1]; 
    }
};