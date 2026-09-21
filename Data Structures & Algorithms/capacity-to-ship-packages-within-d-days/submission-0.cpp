class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN; 
        int high = 0; 

        for(int i = 0; i < weights.size(); i++){
            low = max(low, weights[i]);
            high += weights[i]; 
        }

        while(low < high){
            int mid = low + (high-low)/2;
            
            int daysRequired = 1; 
            int currentWeight = 0; 

            for(auto& weight:weights){
                if(currentWeight + weight > mid){
                    daysRequired++; 
                    currentWeight = 0; 
                }
                currentWeight += weight; 
            }

            if(daysRequired <= days){
                high = mid; 
            }else{
                low = mid+1; 
            }
        }
        return low; 
    }
};