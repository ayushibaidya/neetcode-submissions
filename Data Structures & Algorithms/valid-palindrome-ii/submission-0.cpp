class Solution {
public:

    bool isValidPalindrome(int left, int right, string s){
        while(left < right){
            if(s[left] != s[right]){
                return false; 
            }
            left++; right--; 
        }
        return true; 
    }

    bool validPalindrome(string s) {
        int n = s.size(); 

        int i = 0; int j = n-1; 

        while(i <= j){
            if(s[i] == s[j]){
                i++; j--; 
            }else{
                return isValidPalindrome(i+1, j, s) || isValidPalindrome(i, j-1, s); 
            }
        }
        return true; 
    }
};