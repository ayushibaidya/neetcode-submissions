class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(); 

        int low = 0; 
        int high = n-1; 
        
        while(low <= high){
            if((s[low] < '0' || s[low] > '9') &&
            (s[low] < 'A' || s[low] > 'Z') &&
            (s[low] < 'a' || s[low] > 'z')){
                low++; continue; 
            }else if(((s[high] < '0' || s[high] > '9') &&
            (s[high] < 'A' || s[high] > 'Z') &&
            (s[high] < 'a' || s[high] > 'z'))){
                high--; continue; 
            }
            char c1 = tolower(s[low]);
            char c2 = tolower(s[high]);

            if (c1 != c2) return false;
            low++; high--; 
        }
        return true; 
    }
};
