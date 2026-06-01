class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(); 

        int low = 0; int high = n-1; 

        vector<int> ans;

        while(low <= high){
            int sum = (numbers[high]+numbers[low]); 

            if(target == sum){
                ans.push_back(low+1); 
                ans.push_back(high+1); 
                return ans; 
            }else if(target < sum){
                high--; 
            }else{
                low++; 
            }
        }
        return ans; 
    }
};
