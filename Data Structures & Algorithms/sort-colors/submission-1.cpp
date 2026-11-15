class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); 

        //sort the 0s and 2s - 1s will self sort 
        //i - 0 
        //j - 2 

        int i = 0; 
        int j = n-1; 
        int mid = 0; 

        while(mid <= j){
            if(nums[mid] == 0){
                swap(nums[mid], nums[i]); 
                i++; mid++; 
            }else if(nums[mid] == 1){
                mid++; 
            }else{
                swap(nums[mid], nums[j]); 
                j--; 
            }
        }
    }
};