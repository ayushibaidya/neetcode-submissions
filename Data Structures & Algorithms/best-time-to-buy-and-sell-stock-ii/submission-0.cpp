class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 

        int minDiff = INT_MAX; 
        int profit = 0; 

        for(int i = 0; i < n; i++){
            minDiff = min(minDiff, prices[i]); 
            if(minDiff < prices[i]){
                profit = profit + (prices[i]-minDiff); 
                minDiff = prices[i]; 
            }
        }
        return profit; 
    }
};