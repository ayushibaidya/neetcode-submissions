class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end()); 
        int n = piles.size(); 
        int low = 1; 
        int high = piles[n-1]; 

        while(low < high){
            //mid is k 
            int mid = low + (high-low)/2; 
            int totalHours = 0; 
            for(int i = 0; i < piles.size(); i++){
                totalHours += (piles[i]+mid-1)/mid;  
            }
            if(totalHours <= h){
                high = mid; 
            }else if(totalHours > h){
                low = mid+1; 
            }
        }
        return low;  
    }
};
