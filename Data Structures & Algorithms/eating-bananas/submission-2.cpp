class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end()); 

        int n = piles.size(); 

        int low = 1; int high = *max_element(piles.begin(), piles.end()); 

        int ans = high; 

        while(low <= high){
            int mid = low+(high-low)/2; 
            int hours = 0; 
            for(int p:piles){
                hours+= (p+mid-1)/mid; 
            }
            if(hours > h){
                low = mid+1; 
            }else if(hours <= h){
                ans = mid; 
                high = mid-1;  
            }
        }
        return ans; 
    }
};
