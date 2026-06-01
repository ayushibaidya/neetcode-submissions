class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force 
        int n = prices.size(); 

        int profit = 0; 

        for(int i = 0; i < n; i++){
            int currProfit = 0; 
            for(int j = i+1; j < n; j++){
                if(prices[j] > prices[i]){
                    currProfit = max(currProfit, prices[j]-prices[i]); 
                }
            }
            profit = max(profit, currProfit); 
        }
        return profit; 
    }
};
