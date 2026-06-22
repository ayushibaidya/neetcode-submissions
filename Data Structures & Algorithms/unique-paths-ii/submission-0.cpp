class Solution {
public:

    int func(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int i, int j){
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0; 
        if(i == 0 && j == 0) return 1; 
        if(i < 0 || j < 0) return 0; 

        if(dp[i][j] != -1){
            return dp[i][j]; 
        }

        int up = func(obstacleGrid, dp, i-1, j); 
        int left = func(obstacleGrid, dp, i, j-1); 
        return dp[i][j] = up+left; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(); 
        int m = obstacleGrid[0].size(); 

        vector<vector<int>> dp(n, vector<int> (m, -1)); 
        return func(obstacleGrid, dp, n-1, m-1); 
    }
};