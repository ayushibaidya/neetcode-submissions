class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 

        int maxPile = *max_element(piles.begin(), piles.end()); 
        for(int i = 1; i <= maxPile; i++){
            long long hours = 0; 

            for(int p:piles){
                hours += (p+i-1)/i; 
            }
            if(hours <= h){
                return i; 
            }
        }
        return maxPile; 
    }
};
