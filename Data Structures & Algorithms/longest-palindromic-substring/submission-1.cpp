class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 

        string ans = "";  

        for(int m = 0; m < n; m++){
            int i = m; int j = m; 
            //odd length 
            while(i >= 0 && j < n && s[i] == s[j]){
                    if(ans.size() < j-i+1){
                    ans = s.substr(i, j-i+1); 
                } 
                    i--; j++;
            }
            i = m; j = m+1; 
            while(i >= 0 && j < n && s[i] == s[j]){
                    if(ans.size() < j-i+1){
                    ans = s.substr(i, j-i+1); 
                } 
                    i--; j++;
            }
        }
        return ans; 
    }
};
