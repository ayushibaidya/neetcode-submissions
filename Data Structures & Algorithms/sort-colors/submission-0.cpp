class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); 

        int i = 0; int j = n-1; 
        int mid = 0; 

        while(mid <= j){
            if(nums[mid] == 0){
                swap(nums[i], nums[mid]); 
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