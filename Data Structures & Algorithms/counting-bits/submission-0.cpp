class Solution {
public:

    void  counting(vector<int> &ans, int n){
        if(n == 0){
            ans.push_back(0);
            return; 
        } 
    int count = 0; 
        while(n > 0){
            int bit = n%2; 
            if(bit == 1){
                count++; 
            }
            n /= 2; 
        }
        ans.push_back(count); 
        return; 
    }

    vector<int> countBits(int n) {
        int count = 0; 
        vector<int> ans; 

        for(int i = 0; i <=n; i++){
            counting(ans, i); 
        }
        return ans;
    }
};
