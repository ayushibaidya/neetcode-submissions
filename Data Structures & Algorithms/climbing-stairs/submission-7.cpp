class Solution {
public:

    int memoize(vector<int> &dp, int n){
        if(n == 0 || n == 1) return 1;  

        if(dp[n] != -1) return dp[n]; 
        return dp[n] = memoize(dp, n-1) + memoize(dp, n-2); 
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1); 

        return memoize(dp, n); 
    }
};
