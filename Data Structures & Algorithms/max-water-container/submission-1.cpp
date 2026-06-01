class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int i = 0; int j = n-1; 

        int maxArea = 0; 

        while(i < j){
            int minHeight = min(heights[i], heights[j]); 
            int width = j-i; 
            int area = minHeight*width; 
            maxArea = max(maxArea, area); 

            if(heights[i] < heights[j]){
                i++; 
            }else{
                j--; 
            }
        }
        return maxArea; 
    }
};
