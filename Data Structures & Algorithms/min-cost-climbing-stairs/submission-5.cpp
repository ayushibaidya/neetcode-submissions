class Solution {
public:
    int func(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind >= cost.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        return dp[ind] = cost[ind] +
                         min(func(ind + 1, cost, dp),
                             func(ind + 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(func(0, cost, dp),
                   func(1, cost, dp));
    }
};