class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> results(num1.size() + num2.size(), 0); 

        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                int digOne = num1[i] - '0'; 
                int digTwo = num2[j] - '0'; 

                int product = digOne*digTwo; 

                int pos1 = i+j; 
                int pos2 = i+j+1; 

                int sum = product + results[pos2]; 

                results[pos2] = sum%10; 
                results[pos1] += sum/10; 
            }
        }
        string ans = ""; 

        for(int digit:results){
            if(!(ans.empty() && digit == 0)){
                ans += digit + '0'; 
            }
        }
        return ans.empty() ? "0" : ans; 
    }
};
