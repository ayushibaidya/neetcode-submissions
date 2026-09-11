class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /**
        1 2 4 6 

        pre = 1 1 2 8
        suf =  48 24 6 1
        res = 48 24 12 8

        **/ 
        int n = nums.size(); 

        vector<int> pre(n); 
        vector<int> suf(n); 

        pre[0] = 1; 
        suf[n-1] = 1; 

        //build prefix 
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1]*nums[i-1]; 
        }

        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1]*nums[i+1]; 
        }

        //build res
        vector<int> res(n); 
        for(int i = 0; i < n; i++){
            res[i] = pre[i]*suf[i]; 
        }

        return res; 
    }
};
