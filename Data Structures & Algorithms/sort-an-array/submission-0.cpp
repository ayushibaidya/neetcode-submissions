class Solution {
public:

    void merge(int left, int mid, int right, vector<int> &nums){
        vector<int> temp; 

        int i = left; 
        int j = mid+1; 

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]); 
                i++; 
            }else{
                temp.push_back(nums[j]); 
                j++; 
            }
        } 

        while(i <= mid){
            temp.push_back(nums[i]); 
            i++; 
        }

        while(j <= right){
            temp.push_back(nums[j]); 
            j++; 
        }
        for(int k = 0; k < temp.size(); k++){
            nums[left+k] = temp[k]; 
        }
    }

    void mergeSort(int left, int right, vector<int> &nums){
        if(left >= right){
            return; 
        }
        int mid = (left+right)/2; 

        mergeSort(left, mid, nums); 
        mergeSort(mid+1, right, nums);  

        merge(left, mid, right, nums); 
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size(); 

        mergeSort(0, n-1, nums); 
        return nums; 
    }
};