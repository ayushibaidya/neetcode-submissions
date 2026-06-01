class Solution {
public:
    int maxArea(vector<int>& heights) {
        int areaMax = 0; 

        int low = 0; int high = heights.size()-1; 

        while(low < high){
            int minHeight = min(heights[low], heights[high]); 
            areaMax = max(areaMax, minHeight*(high-low)); 
            if(heights[low] < heights[high]){
                low++; 
            }else{
                high--;
            }
        }
        return areaMax; 
    }
};
