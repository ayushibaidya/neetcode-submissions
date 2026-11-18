class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(); 

        int i = 0; int j = n-1; 

        while(i <= j){
        if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9')){
            i++; continue; 
        }if((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z') && (s[j] < '0' || s[j] > '9')){
            j--; continue; 
        }
        char a = tolower(s[i]); 
        char b = tolower(s[j]); 
        if(a != b) return false; 
        i++; j--;
        }
        return true; 
    }
};
