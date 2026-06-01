class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(); 

        int i = 0; int j = n-1; 

        while(i <= j){
            if((s[i] < '0' || s[i] > '9') &&
                (s[i] < 'a' || s[i] > 'z') &&
                (s[i] < 'A' || s[i] > 'Z')){
                    i++; continue; 
            }
            if((s[j] < '0' || s[j] > '9') &&
                (s[j] < 'a' || s[j] > 'z') && 
                (s[j] < 'A' || s[j] > 'Z')){
                    j--; continue; 
            }
            char c1 = tolower(s[i]); 
            char c2 = tolower(s[j]); 
            if(c1 != c2) return false; 
            i++; j--; 
        }
        return true; 
    }
};
